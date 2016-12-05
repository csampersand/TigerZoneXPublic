//
//  LogInterface.cpp
//  TigerZoneX
//
//  Created by Connor Elkin on 12/2/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "LogInterface.hpp"
#include <iostream>
#include <stdio.h>

int LogInterface::printBoard(){
    
    int count = 0;
    
    std::cout << "Printing the Game Board..." << std::endl;
    for(int i = 152; i>=0; i--){
        for(int j=0; j<153; j++){
            if(this->getGame().getBoard()->getTileRelation(j, i)!=NULL){
                std::cout << "X";
                count++;
            }
            else{
                std::cout << "-";
                count++;
            }
        }
        std::cout << std::endl;
    }
    
    return count;

};

void LogInterface::update(){
    
    
};
