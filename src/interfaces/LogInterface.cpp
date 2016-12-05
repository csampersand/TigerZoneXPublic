//
//  LogInterface.cpp
//  TigerZoneX
//
//  Created by Connor Elkin on 12/2/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "LogInterface.hpp"
#include <iostream>
#include <stdio.h>

int LogInterface::printBoard(){
    
    int count = 0;
    
    std::cout << "Printing the Game Board..." << std::endl;
    for(int i = 152; i>=0; i--){
        for(int j=0; j<153; j++){
            if(this->getGame().getBoard()->getTileRelation(j, i)!=NULL){
                std::cout << "X";
                count++;
            }
            else{
                std::cout << "-";
                count++;
            }
        }
        std::cout << std::endl;
    }
    
    return count;

};

void LogInterface::update(){
    Move printMoveObject;
    //printMoveObject = this->getInteractor().getLastMove();
   // printMove(&printMoveObject);
    
    
    
};

std::string LogInterface::returnTileSequence(Tile* tile){
    std::string str = "";
    char n,e,w,s;
    char specialCode;
    if(tile->getCenterType() == 'X'){
        specialCode = 'X';
    }
    else if (tile->getPreyType()==Tile::null){
        specialCode = '-';
    }
    else{
        specialCode = tile->getPreyType();
    }
    n = tile->getNType();
    e = tile->getEType();
    s = tile->getSType();
    w = tile->getWType();
    str += n;
    str += e;
    str += s;
    str += w;
    str += specialCode;
    
    return str;
}

void LogInterface::printMove(Move* move){
    
    if(move->tigerZone!=0){
    
    std::cout << "Player " << move->playerId << " played the Tile " << returnTileSequence(move->tile) << " at coordinates " << move->x << ", " << move->y << " with orientation " << move->rotations << " and placed a Tiger in zone " << move->tigerZone << ".";
    }
    if(move->croc){
    std::cout << "Player " << move->playerId << " played the Tile " << returnTileSequence(move->tile) << " at coordinates " << move->x << ", " << move->y << " with orientation " << move->rotations << " and placed a Crocodile.";
    }
    
    if(!move->croc){
    std::cout << "Player " << move->playerId << " played the Tile " << returnTileSequence(move->tile) << " at coordinates " << move->x << ", " << move->y << " with orientation " << move->rotations << " and placed Nothing.";
    }
}


