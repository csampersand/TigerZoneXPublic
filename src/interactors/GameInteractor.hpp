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
#include "TileLandmark.hpp"

class GameInteractor {
private:
    Game* game;
public:
    // Initialize game, setup deck, setup board
    GameInteractor();
    GameInteractor(Game*);
    
    //TileDeck
    // Shuffle the deck
	void shuffleDeck();
    // Create a tile from Dave's defined tile sequences
	static Tile* createTileFromSequence(std::string);
    // Create a tile from alphabetic template
    static Tile* createTileFromTemplate(char);
    // Create a vector of all the game tiles
    static std::vector<Tile*> defineTiles();
    // Return the top tile from the deck, and remove it
    Tile* drawTile();
    // Define tiles, shuffle them, and add tile type S at the top
    void setupTileDeck();

    //Tile
    // Rotate a tile clockwise once
    static void rotateTile(Tile*);
    // Rotate a tile clockwise n times
    static void rotateTile(Tile*, int);
    
    //Board
    bool isPlacementValid(int, int, Tile*);
    void placeLandmarks(int, int, Tile*);
    bool placeTile(int, int, Tile*);
    bool placeTiger(int, int, int, Player*);
    bool placeCrocodile(int, int, Player*);
    // Set first tile, at (73,73), to tile at top of deck
    void setupBoard();
    
    //Player
    // Setup 2-player game and alot tigers & crocodiles
    void setupPlayers();
};

#endif /* GameInteractor_hpp */
