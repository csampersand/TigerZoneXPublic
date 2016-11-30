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
#include <iostream>

//class TestTile : public Tile {
//public:
//	SideType getNType() {
//		SideType type = static_cast<SideType>(nType);
//	}
//	SideType getEType();
//	SideType getSType();
//	SideType getWType();
//};
//
//class TestTileRelation : public TileRelation {
//public:
//    TestTile* getTile(){
//        TestTile* testTile = static_cast<TestTile*>(tile);
//        return testTile;
//    }
//    
//};

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
    
//    TileRelation* getTile() {
//        return this->tiles;
//    }
    
    //TestTileRelation* getTiles(){
    //    TestTileRelation* testTiles = static_cast<TestTileRelation*>(tiles);
    //    return testTiles;
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

TEST_CASE("Testing the Place Landmark function"){
    Tile* tile1 = TestGameInteractor::createTileFromTemplate('E');
    Tile* tile2 = TestGameInteractor::createTileFromTemplate('S');
////    Tile* tile3 = TestGameInteractor::createTileFromTemplate('');
////    Tile* tile4 = TestGameInteractor::createTileFromTemplate('E');
//
//
    TestGameInteractor* tgi = new TestGameInteractor();
    //76 76
    tgi->placeTile(75,76, tile1);
    tgi->placeLandmarks(75,76, tile1);
    tgi->placeTile(75,75, tile1);
    tgi->placeLandmarks(75,75, tile1);
    tgi->placeTile(75,74, tile1);
    tgi->placeLandmarks(75,74, tile1);
    tgi->placeTile(76,74, tile1);
    tgi->placeLandmarks(76,74, tile1);
    tgi->placeTile(76,75, tile1);
    tgi->placeLandmarks(76,75, tile1);


    SECTION("tile placed has connected two trails"){
////        tgi->placeTile(72,74,tile2);
        TileLandmark* lam = tgi->getGame()->getBoard()->getTileLandmark(76,76,8);
//        std::cout << lam->getLandmarkType() <<std::endl;
        TileTrail* trail;
        trail = &static_cast<TileTrail&>(*lam);
//        std::cout << "next: " << trail->getNextTrail() << std::endl;
//        std::cout << "prev: " << trail->getPrevTrail() << std::endl;

        if(trail->getNextTrail() != NULL){
            trail = trail->getNextTrail()->getNextTrail();
        }
        else if(trail->getPrevTrail() != NULL){
            trail = trail->getPrevTrail()->getPrevTrail();
        }
        else{
            std::cout << "Both are null\n";
        }
//        trail = trail->getNextTrail()->getNextTrail();
        TileLandmark* temp = tgi->getGame()->getBoard()->getTileLandmark(76,74,2);
        TileTrail* trail2;
        trail2 = &static_cast<TileTrail&>(*temp);

//TEST_CASE("does the tile place"){
//    TestGameInteractor* gameInt = new TestGameInteractor::TestGameInteractor();
//
//    Tile* tempTile = gameInt->drawTile();
//    gameInt->placeTile(72,73,tempTile);
//    Tile* placedTile = gameInt->getTilePointer(72, 73);
//
//
//    SECTION("placing tile"){
//        INFO("tile is being placed")
//        REQUIRE(tempTile == placedTile);
//
//    }
//
//
//}

        INFO("connecting two seperate trails")
        REQUIRE(trail==trail2);
    }
}
////    SECTION("tilelandmark is not completed"){
////        tgi->placeTile(72,74,tile2);
////        INFO("tilelandmark was not bool completed")
////        REQUIRE();
////    }
//}
//
//TEST_CASE("Testing Tile class") {
//    Tile* t = new Tile::Tile(Tile::sideLake, Tile::sideJungle, Tile::sideTrail, Tile::sideTrail, Tile::centerLake);
//
//    SECTION("rotating the tile") {
//        INFO("Rotating 3 times")
//        GameInteractor::rotateTile(t,3);
//        REQUIRE(t->getNType() == Tile::sideJungle);
//        REQUIRE(t->getEType() == Tile::sideTrail);
//        REQUIRE(t->getSType() == Tile::sideTrail);
//        REQUIRE(t->getWType() == Tile::sideLake);
//    }
//}
//
//TEST_CASE("does it shuffle deck"){
//    TestGameInteractor* gameInt = new TestGameInteractor::TestGameInteractor();
//
//
//    SECTION("shuffling the deck"){
//        INFO("deck is being shuffled")
//        std::vector<Tile*> deck1 = gameInt->defineTiles();
//        gameInt->getGame()->deck = deck1;
//        //std::vector<Tile *> deck2 = deck1.shuffleDeck();
//
//        Tile* fTile = GameInteractor::createTileFromTemplate('F');
//        bool one = (tile->getNType() != fTile->getNType());
//
//        bool two = (tile->getSType() != fTile->getSType());
//        bool three = (tile->getWType() != fTile->getWType());
//        bool four = (tile->getEType() != fTile->getEType());
//        bool temp = one && two;
//        bool temp2 = temp && three;
//        bool temp4 = temp2 && four;
//        REQUIRE(temp4);
//
//
//
//    }
//}


//TEST_CASE("does the tile place"){
//    TestGameInteractor* gameInt = new TestGameInteractor::TestGameInteractor();
//
//    Tile* tempTile = gameInt->drawTile();
//    gameInt->placeTile(72,73,tempTile);
//    Tile* placedTile = gameInt->getTilePointer(72, 73);
//
//
//    SECTION("placing tile"){
//        INFO("tile is being placed")
//        REQUIRE(tempTile == placedTile);
//
//    }
//
//
//}

TEST_CASE("Does the trails append?"){
    SECTION("appending now"){
        TestGameInteractor* testgi = new TestGameInteractor();
        //testgi
        Tile* tile1 = TestGameInteractor::createTileFromTemplate('S');
        //Tile* tile2 = TestGameInteractor::createTileFromTemplate('S');
        testgi->placeTile(76,75, tile1);
        //static_cast<TileTrail*>(TileLandmark)
        TileLandmark* tl = testgi->getGame()->getBoard()->getLandmark(76,76,8);
        TileLandmark* tl2 = testgi->getGame()->getBoard()->getLandmark(76,75,2);
        INFO("Appended")
//        REQUIRE(before->getNextTrail() == after);
//        REQUIRE(after->getPrevTrail() == before);
        REQUIRE(!testgi->isComplete(tl));

    }
}

//Testing has Owner
TEST_CASE("Testing isComplete and lakes") {

	//Start a test game interactor
	TestGameInteractor* gi = new TestGameInteractor();

	Tile* t7776 = gi->createTileFromTemplate('A');
	Tile* t7777 = gi->createTileFromTemplate('J');
	Tile* t7778 = gi->createTileFromTemplate('M');
	gi->rotateTile(t7778, 2);
	Tile* t7878 = gi->createTileFromTemplate('M');
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
    gi->placeLandmarks(77, 76, t7776);
	gi->placeTile(77, 77, t7777);
    gi->placeLandmarks(77, 77, t7777);
	gi->placeTile(77, 78, t7778);
    gi->placeLandmarks(77, 78, t7778);
	gi->placeTile(78, 78, t7878);
    gi->placeLandmarks(78, 78, t7878);
	gi->placeTile(78, 77, t7877);
    gi->placeLandmarks(78, 77, t7877);
	Player* player2 = new Player();
	

	
	gi->placeTile(78, 76, t7876);
    gi->placeLandmarks(78, 76, t7876);
	gi->placeTile(79, 77, t7977);
    gi->placeLandmarks(79, 77, t7977);
	gi->placeTile(79, 76, t7976);
    gi->placeLandmarks(79, 76, t7976);
	gi->placeTile(79, 75, t7975);
    gi->placeLandmarks(79, 75, t7975);
	gi->getGame()->getBoard()->getLandmark(79, 76, 5)->setTigerOwner(player2);;
    std::cout << "78,76" << std::endl;
    std::cout << "n: " << gi->getGame()->getBoard()->getTileRelation(78,76)->getTile()->getNType() << std::endl;
	std::cout << "79,75" << std::endl;
	std::cout << "n: " << gi->getGame()->getBoard()->getTileRelation(79,75)->getTile()->getNType() << std::endl;

    SECTION("Layed some sweet tile") {
    	//grabbing tile landmark at 79,76 zone 2
    	TileLandmark* tl = gi->getGame()->getBoard()->getLandmark(79,76,5);
    	bool firstTest = gi->isComplete(tl);
    	Player* getP2 = gi->getOwner(tl); 

        INFO("checking isComplete and landmark")
        REQUIRE(firstTest);
        REQUIRE(getP2 == player2);
    }
	
}
