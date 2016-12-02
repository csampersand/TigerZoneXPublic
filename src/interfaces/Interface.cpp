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
}

Game& Interface::getGame() {
    return this->interactor.getGame();
}

GameInteractor& Interface::getInteractor() {
    return this->interactor;
}

void GameInteractor::notifyInterfaces() {
    for (auto i : views) {
        i->update();
    }
}
