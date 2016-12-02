//
//  Interface.cpp
//  TigerZoneX
//
//  Created by Chris on 12/1/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "Interface.hpp"

Interface::Interface(GameInteractor& interactor) {
    this->interactor = interactor;
    this->model = interactor.getGame();
}

Game& Interface::getGame() {
    return this->model;
}

GameInteractor& Interface::getInteractor() {
    return this->interactor;
}
