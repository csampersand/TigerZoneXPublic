//
//  TileLandmark.cpp
//  TigerZoneX
//
//  Created by Chris on 11/19/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "TileLandmark.hpp"

TileLandmark::TileLandmark(){
    this->tigerOwnedBy = NULL;
    this->tigerCount = 0;
    this->hasCrocodile = false;
    this->type = NULL;
}

void TileTrail::trailEnd(bool end) {
    trailEnds = end;
}

LandmarkType TileLandmark::getType() {
    return this->type;
}

void TileLandmark::setLandmarkType(LandmarkType type) {
    this->type = type;
}

TileTrail::TileTrail(){
    this->nextTrail = NULL;
    this->prevTrail = NULL;
    this->trailEnds = false;
    this->hasCrocodile = false;
}

TileTrail* TileTrail::getNextTrail() {
    return this->nextTrail;
}

TileTrail* TileTrail::getPrevTrail() {
    return this->prevTrail;
}

void TileTrail::setNextTrail(TileTrail* next) {
    this->nextTrail = next;
}

void TileTrail::setPrevTrail(TileTrail* prev) {
    this->prevTrail = prev;
}

bool TileTrail::getTrailEnds() {
    return this->trailEnds;
}

void TileTrail::setTrailEnds(bool ends) {
    this->trailEnds = ends;
}

TileLake::TileLake(){
    this->nLake = NULL;
    this->eLake = NULL;
    this->sLake = NULL;
    this->wLake = NULL;
    this->nOpen = false;
    this->eOpen = false;
    this->sOpen = false;
    this->wOpen = false;
    this->lakeEnds = false;
    this->hasCrocodile = false;
}

bool TileLake::getHasCrocodile() {
    return this->hasCrocodile;
}

void TileLake::setHasCrocodile(bool crocodile) {
    this->hasCrocodile = crocodile;
}

TileLake* TileLake::getNLake() {
    return this->nLake;
}
TileLake* TileLake::getELake() {
    return this->eLake;
}
TileLake* TileLake::getSLake() {
    return this->sLake;
}
TileLake* TileLake::getWLake() {
    return this->wLake;
}
void TileLake::setNLake(TileLake* TileLake) {
    this->nLake = TileLake;
}
void TileLake::setELake(TileLake* TileLake) {
    this->eLake = TileLake;
}
void TileLake::setSLake(TileLake* TileLake) {
    this->sLake = TileLake;
}
void TileLake::setWLake(TileLake* TileLake) {
    this->wLake = TileLake;
}
bool TileLake::getNOpen() {
    return this->nOpen;
}
bool TileLake::getEOpen() {
    return this->eOpen;
}
bool TileLake::getSOpen() {
    return this->sOpen;
}
bool TileLake::getWOpen() {
    return this->wOpen;
}
void TileLake::setNOpen(bool open) {
    this->nOpen = open;
}
void TileLake::setEOpen(bool open) {
    this->eOpen = open;
}
void TileLake::setSOpen(bool open) {
    this->sOpen = open;
}
void TileLake::setWOpen(bool open) {
    this->wOpen = open;
}

TileDen::TileDen(){
    this->surroundingTiles = NULL;
}

int TileDen::getX() {
    return this->x;
}

int TileDen::getY() {
    return this->y;
}

void TileDen::setX(int x) {
    this->x = x;
}

void TileDen::setY(int y) {
    this->y = y;
}

Player* TileLandmark::getTigerOwner() {
    return this->tigerOwner;
}

void TileLandmark::setTigerOwner(Player* player) {
    this->tigerOwner = player;
}
