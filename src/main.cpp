//
//  main.cpp
//  TigerZoneX
//
//  Created by Chris on 11/4/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include <iostream>
#include "SocketInterface.hpp"

int main(int argc, const char * argv[]) {
    GameInteractor gi;
    SocketInterface s(gi, argv[1], argv[2], argv[3], argv[4], argv[5]);

    return 0;
}
