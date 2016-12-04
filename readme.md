# TigerZone Group X  
## Members  
* Chris Anderson
* Connor Elkin
* Jacob Gonzales
* Will Hsiung

## Architecture and design  
Our UML Diagram of our architecture, designed as a clean architecture with only inward pointing dependences (Adapters → Use Cases → Entities).
![](UML/Architecture.png)

## How to build  
You will need to have boost installed. On OS X with homebrew, all you need to do is run `brew install boost`.

On Windows, download boost from [here](http://www.boost.org/users/history/version_1_55_0.html) and modify the makefile to point BOOST_LIB and BOOST_INCLUDE to the correct directories in the downloaded files.

Run `make` in the project directory

## How to run  
Run `build/Release/TigerZoneX <IP> <PORT> <TOURNAMENT_PASSWORD> <TEAM_USERNAME> <TEAM_PASSWORD>`

## How to run tests  
Run `build/Release/TestTigerZoneX`

Our current tests are made to test the units and acceptance of our entities and use cases (located in models/ and interactors/ respectively)

## Known issues will be listed in the issue tracker