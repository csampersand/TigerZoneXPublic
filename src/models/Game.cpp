//
//  Game.cpp
//  TigerZoneX
//
//  Created by Chris on 11/27/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "Game.hpp"

Game::Game() {
    board = new Board();
    deck = new TileDeck();
    for (Player* player : players) {
        player = new Player();
    }
    turnIndex = 0;
}

Board* Game::getBoard() {
    return this->board;
}

TileDeck* Game::getDeck() {
    return this->deck;
}

Player* Game::getPlayer(int i) {
    return this->players[i];
}

int Game::getTurnIndex() {
    return this->turnIndex;
}
