//
//  testTile.cpp
//  TigerZoneX
//
//  Created by Chris on 11/11/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "catch.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "TileLandmark.hpp"
#include "Game.hpp"
#include "TileDeck.hpp"
#include "GameInteractor.hpp"


//class TestTileLandmark : public TileLandmark {
//public:
//	void setTigerCount(Player* player){
//		this->tigerCount = tigers;
//		this->tigerOwner = player;
//	}
//};

class TestBoard : public Board {
public:
	//TestTileLandmark* getLandmark(){
	//	TestTileLandmark* testTileLandmark = static_cast<TestTileLandmark*>(tileLandmark);
 //       return testTileLandmark;
	//}

    TileLandmark* getLandmark(int x, int y, int zone){
        return this->getTileLandmark(x, y, zone);
    }
};

class TestGame : public Game {
public:
    TestBoard* getBoard() {
        TestBoard* testBoard = static_cast<TestBoard*>(board);
        return testBoard;
    }
    TileDeck* getDeck(){
        return this->deck;
    }
};

class TestGameInteractor : public GameInteractor {
public:
    TestGame* getGame() {
        TestGame* testGame = static_cast<TestGame*>(game);
        return testGame;
    }
    //    std::vector<Tile*> getDeck() {
    //        return this->game->deck->Deck;
    //    }
    
    std::vector<Tile*> getTilePointer(){
        return this->getGame()->getDeck()->getTiles();
    }
};

TEST_CASE("Testing Tile class") {
	TestGameInteractor* gi = new TestGameInteractor();
    Tile *t = new Tile(Tile::sideLake, Tile::sideJungle, Tile::sideTrail, Tile::sideTrail, Tile::centerLake);
	gi->rotateTile(t, 3);
    SECTION("rotating the tile") {
        INFO("Rotating 3 times")
        
        REQUIRE(t->getNType() == Tile::sideJungle);
        REQUIRE(t->getEType() == Tile::sideTrail);
        REQUIRE(t->getSType() == Tile::sideTrail);
        REQUIRE(t->getWType() == Tile::sideLake);
    }
}

//Testing has Owner
TEST_CASE("Testing Tile class") {

	//Start a test game interactor
	TestGameInteractor* gi = new TestGameInteractor();

	Tile* t7776 = gi->createTileFromTemplate('A');
	Tile* t7777 = gi->createTileFromTemplate('J');
	Tile* t7778 = gi->createTileFromTemplate('F');
	gi->rotateTile(t7778, 2);
	Tile* t7878 = gi->createTileFromTemplate('F');
	gi->rotateTile(t7878,2);
	Tile* t7877 = gi->createTileFromTemplate('H');
	Tile* t7876 = gi->createTileFromTemplate('M');
	Tile* t7977 = gi->createTileFromTemplate('J');
	gi->rotateTile(t7977,2);
	Tile* t7976 = gi->createTileFromTemplate('K');
	gi->rotateTile(t7976,1);
	Tile* t7975 = gi->createTileFromTemplate('M');

	//gi->playTurn();
	gi->placeTile(77, 76, t7776);
	gi->placeTile(77, 77, t7777);
	gi->placeTile(77, 78, t7778);
	gi->placeTile(78, 78, t7878);
	gi->placeTile(78, 77, t7877);
	Player* player2 = new Player();
	gi->getGame()->getBoard()->getLandmark(78,77,5)->setTigerOwner(player2);;

	
	gi->placeTile(78, 76, t7876);
	gi->placeTile(79, 77, t7977);
	gi->placeTile(79, 76, t7976);
	gi->placeTile(79, 75, t7975);

    SECTION("Layed some sweet tile") {
    	//grabbing tile landmark at 79,76 zone 2
    	TileLandmark* tl = gi->getGame()->getBoard()->getLandmark(79,76,2);
    	bool firstTest = gi->isComplete(tl);
    	Player* getP2 = gi->getOwner(tl); 

        INFO("checking isComplete and landmark")
        REQUIRE(firstTest);
        REQUIRE(getP2 == player2);

    }
}