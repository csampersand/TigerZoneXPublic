//
//  Board.cpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#include "Board.hpp"

Board::Board() {
	for (int i = 0; i < 153; i++) {
		for (int j = 0; j < 153; j++) {
			tiles[i][j] = NULL;
		}
	}
	for (int i = 0; i < 153; i++) {
		for (int j = 0; j < 153; j++) {
			for (int k = 0; k < 10; k++) {
				landmarks[i][j][k] = NULL;
			}
		}
	}
	firstTile = NULL;
}

TileRelation* Board::getTileRelation(int x, int y){
    return this->tiles[x][y];
};

TileLandmark* Board::getTileLandmark(int x, int y, int zone){
    return this->landmarks[x][y][zone];
}

void Board::setTileLandmark(int x, int y, int zone, TileLandmark* landmark) {
    this->landmarks[x][y][zone] = landmark;
}

void Board::setTileRelation(int x, int y, TileRelation* relation) {
    this->tiles[x][y] = relation;
}

TileRelation* Board::getFirstTile() {
    return this->firstTile;
}

void Board::setFirstTile(TileRelation* relation) {
    this->firstTile = relation;
}
