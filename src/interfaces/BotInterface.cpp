//
//  BotInterface.cpp
//  TigerZoneX
//
//  Created by Chris on 12/1/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "BotInterface.hpp"
#include <vector>
#include <chrono>
#include <random>

void BotInterface::update()
{
    if (myTurn) {
        //GameInteractor g = this->getInteractor();
        std::vector<Move> moves = listPossibleMoves();

        typedef std::chrono::high_resolution_clock myclock;
        myclock::time_point beginning = myclock::now();
        myclock::duration d = myclock::now() - beginning;
        unsigned seed = d.count();
        auto engine = std::default_random_engine{};
        engine.seed(seed);
        std::shuffle(std::begin(moves), std::end(moves), engine);
        
       // this->setMoves(moves);

        //pick a random move
        Move move = moves.front();
        //play the move
        if(move.tigerZone == 0)
            this->getInteractor().playTurn(move.x, move.y, move.rotations, false, move.croc, move.tigerZone);
        else
            this->getInteractor().playTurn(move.x, move.y, move.rotations, true, move.croc, move.tigerZone);
    }
    myTurn = !myTurn;
}

void BotInterface::visitCoord(std::pair<int, int> coord, Tile* tile, int PID, std::queue< std::pair<int, int> > queue, bool visited[][153], std::vector<Move> foundMoves) {
    //Mark current coord as visited
    visited[coord.first][coord.second] = true;
    
    //Possible move location found
    if (this->getInteractor().getGame().getBoard()->getTileRelation(coord.first, coord.second) == NULL) {
        //Find any possible moves at coord, given tile
        Tile* tempTile = new Tile(tile->getNType(), tile->getEType(), tile->getSType(), tile->getWType(), tile->getCenterType(), tile->getPreyType());
        for (int i = 0; i < 4; ++i) {
            this->getInteractor().rotateTile(tempTile);
            if (this->getInteractor().isPlacementValid(coord.first, coord.second, tempTile)) {
                //Valid tile orientation found
                //TODO find valid tiger and croc placements per rotation
                int tempZone = 0;
                
                //looks to see if tile has a den
                if(tempTile->getCenterType() == Tile::centerDen){
                    tempZone = 5;
                }
                
                //looks for a place to put tigers
                GameInteractor gTemp = this->getInteractor();
                gTemp.placeTile(coord.first, coord.second, tempTile);
                for(int j = 0; j<9; j++){
                    TileLandmark* tempLandmark = gTemp.getGame().getBoard()->getTileLandmark(coord.first, coord.second, j);
                    if(!gTemp.hasOwner(tempLandmark)){
                        tempZone = j;
                    }
                }
                
                foundMoves.push_back(Move(PID, coord.first, coord.second, tile, i, false, tempZone));
                
            }
        }
        delete tempTile;
    }
    //Keep searching
    else {
        int xx[] = { coord.first, coord.first + 1, coord.first, coord.first - 1 };
        int yy[] = { coord.second + 1, coord.second, coord.second - 1, coord.second };
        for (int i = 0; i < 4; ++i) {
            //if coord is out of bounds or has already been visited do not add to queue
            if (xx[i] > 152 || xx[i] < 0 || yy[i] > 152 || yy[i] < 0) continue;
            if (visited[xx[i]][yy[i]]) continue;
            
            queue.push(std::make_pair(xx[i], yy[i]));
        }
    }
    delete tile;
}


std::vector<Move> BotInterface::listPossibleMoves() {
    std::vector<Move> validMoves;
    std::queue< std::pair<int, int> > queue;
    bool visited[153][153] = {false};
    
    //Start BFS
    queue.push(std::make_pair(76, 76));
    std::pair<int, int> nextCoord;
    while (queue.size() > 0) {
        //Visit the next coord
        nextCoord = queue.front();
        queue.pop();
        visitCoord(nextCoord, this->getInteractor().getGame().getDeck()->getTiles().front(), this->getInteractor().getGame().getTurnIndex(), queue, visited, validMoves);
    }
    
    return validMoves;
}

//std::vector<Move> BotInterface::listPossibleMoves(){
//    std::vector<Move> validMoves;
//    std::queue< std::pair<int, int> > queue;
//    bool visited[153][153];
//    
//    //Start BFS
//    queue.push(std::make_pair(76, 76));
//    std::pair<int, int> nextCoord;
//    while(queue.size() > 0){
//        
//    }
//    
//    
//}

void BotInterface::setTigerZone(Move move){
    
    
    
    
}
