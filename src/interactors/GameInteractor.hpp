//
//  GameInteractor.hpp
//  TigerZoneX
//
//  Created by Chris on 11/27/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef GameInteractor_hpp
#define GameInteractor_hpp

#include <stdio.h>
#include "Game.hpp"
#include "Tile.hpp"
#include "TileDeck.hpp"

class GameInteractor {
private:
    Game* game;
public:
    GameInteractor();
    GameInteractor(Game*);
    
    //TileDeck
	void shuffleDeck(TileDeck*);
	static Tile* createTileFromSequence(std::string);
    static Tile* createTileFromTemplate(char);
    static std::vector<Tile*> defineTiles();

    

    //Tile
    static void rotateTile(Tile*);
    static void rotateTile(Tile*, int);
    
    //Board
    bool isPlacementValid(int, int, Tile*);
    bool placeTile(int, int, Tile*);

};

#endif /* GameInteractor_hpp */
