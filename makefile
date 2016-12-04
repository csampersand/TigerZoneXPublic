BOOST_LIB=/usr/local/Cellar/boost/1.60.0_2/lib
BOOST_INCLUDE=/usr/local/Cellar/boost/1.60.0_2/include
INC=-Isrc/models -Isrc/interactors -Isrc/interfaces -I$(BOOST_INCLUDE)
LIB=-L$(BOOST_LIB)
LIBS=-lboost_system
CATCH=-Itests/catch.hpp

#this target will compile all files
all: TigerZoneX TestTigerZoneX clean

TigerZoneX: main.o GameInteractor.o BotInterface.o Interface.o SocketInterface.o Board.o Game.o Move.o Player.o Tile.o TileDeck.o TileLandmark.o TileRelation.o
	g++ $(LIB) $(LIBS) main.o GameInteractor.o BotInterface.o Interface.o SocketInterface.o Board.o Game.o Move.o Player.o Tile.o TileDeck.o TileLandmark.o TileRelation.o -o build/Release/TigerZoneX

TestTigerZoneX: testMain.o testAcceptance.o
	g++ $(LIB) $(LIBS) testMain.o testAcceptance.o GameInteractor.o BotInterface.o Interface.o SocketInterface.o Board.o Game.o Move.o Player.o Tile.o TileDeck.o TileLandmark.o TileRelation.o -o build/Release/TestTigerZoneX

main.o: src/main.cpp
	g++ -std=c++11 $(INC) -c src/main.cpp

GameInteractor.o: src/interactors/GameInteractor.cpp
	g++ -std=c++11 $(INC) -c src/interactors/GameInteractor.cpp

BotInterface.o: src/interfaces/BotInterface.cpp
	g++ -std=c++11 $(INC) -c src/interfaces/BotInterface.cpp

Interface.o: src/interfaces/Interface.cpp
	g++ -std=c++11 $(INC) -c src/interfaces/Interface.cpp

SocketInterface.o: src/interfaces/SocketInterface.cpp
	g++ -std=c++11 $(INC) -c src/interfaces/SocketInterface.cpp

Board.o: src/models/Board.cpp
	g++ -std=c++11 $(INC) -c src/models/Board.cpp

Game.o: src/models/Game.cpp
	g++ -std=c++11 $(INC) -c src/models/Game.cpp

Move.o: src/models/Move.cpp
	g++ -std=c++11 $(INC) -c src/models/Move.cpp

Player.o: src/models/Player.cpp
	g++ -std=c++11 $(INC) -c src/models/Player.cpp

Tile.o: src/models/Tile.cpp
	g++ -std=c++11 $(INC) -c src/models/Tile.cpp

TileDeck.o: src/models/TileDeck.cpp
	g++ -std=c++11 $(INC) -c src/models/TileDeck.cpp

TileLandmark.o: src/models/TileLandmark.cpp
	g++ -std=c++11 $(INC) -c src/models/TileLandmark.cpp

TileRelation.o: src/models/TileRelation.cpp
	g++ -std=c++11 $(INC) -c src/models/TileRelation.cpp

testMain.o: tests/main.cpp
	g++ -std=c++11 $(INC) -c tests/main.cpp -o testMain.o

testAcceptance.o: tests/testAcceptance.cpp
	g++ -std=c++11 $(INC) -c tests/testAcceptance.cpp

clean:
	rm -rf *.o