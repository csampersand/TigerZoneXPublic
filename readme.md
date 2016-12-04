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
### For Mac OS X  
Run `xcodebuild` in the project directory

### Using makefile
Run `make` in the project directory

## How to run  
Run `build/Release/TigerZoneX <IP> <PORT> <TOURNAMENT_PASSWORD> <TEAM_USERNAME> <TEAM_PASSWORD>`

## How to run tests  
Run `build/Release/TestTigerZoneX`

Our current tests are made to test the units and acceptance of our entities and use cases (located in models/ and interactors/ respectively)

## Known issues will be listed in the issue tracker