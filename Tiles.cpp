/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tiles.cpp
 * Author: ninou14fr
 * 
 * Created on November 3, 2016, 11:28 PM
 */

#include "Tiles.h"
Tiles::Tiles() {
    
 //Individual tiles initializations
    
    A[0]=new type();
    A[1]=new type();
    
    B[0]=new type();
   
    C[0]=new type();
   
    D[0]=new type();
    D[1]=new type();
    D[2]=new type();  
    D[3]=new type();  
    
    E[0]=new type();
    E[1]=new type();
 
    F[0]=new type();
    F[1]=new type();
    F[2]=new type();
    
    G[0]=new type();
    G[1]=new type();
    G[2]=new type();
    
    H[0]=new type();
    H[1]=new type();
    H[2]=new type();
    
    I[0]=new type();
    I[1]=new type();
    I[2]=new type();
    
    J[0]=new type();
    J[1]=new type();
    J[2]=new type();
    J[3]=new type();
    
    K[0]=new type();
    K[1]=new type();
    K[2]=new type();
    K[3]=new type();

    L[0]=new type();
    L[1]=new type();
    L[2]=new type();
    L[3]=new type();
    L[4]=new type();
    L[5]=new type();
    L[6]=new type();
    
    M[0]=new type();
    M[1]=new type();
    
    N[0]=new type();
    N[1]=new type();

    O[0]=new type();
    O[1]=new type();
    O[2]=new type();
    O[3]=new type();
    
    P[0]=new type();
    P[1]=new type();
    P[2]=new type();
    P[3]=new type();
    
    Q[0]=new type();
    Q[1]=new type();
    
    R[0]=new type();
    R[1]=new type();
    
    S[0]=new type();
    S[1]=new type();
    
    T[0]=new type();
    T[1]=new type();
    T[2]=new type();
    T[3]=new type();
    
    U[0]=new type();
    U[1]=new type();
    U[2]=new type();
    
    V[0]=new type();
    V[1]=new type();
    V[2]=new type();
    
    W[0]=new type();
    W[1]=new type();
    W[2]=new type();
    W[3]=new type();
    W[4]=new type();
    W[5]=new type();
    
    X[0]=new type();
    X[1]=new type();
    X[2]=new type();
    X[3]=new type();
    X[4]=new type();
    X[5]=new type();
    X[6]=new type();
    X[7]=new type();
    
 //Temporary variables for coordinate pointer.
    Coordinate temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;
    
    temp1.NameOfCoordinate="SE";
    temp2.NameOfCoordinate="E";
    temp3.NameOfCoordinate="NE";
    temp4.NameOfCoordinate="N";
    temp5.NameOfCoordinate="NW";
    temp6.NameOfCoordinate="W";
    temp7.NameOfCoordinate="SW";
    temp8.NameOfCoordinate="S";
    
//Following create the tiles
    A[0]->NameOfType="Farm";
        
    A[0]->coordinate->push_back(temp1);
    A[0]->coordinate->push_back(temp2);
    A[0]->coordinate->push_back(temp3);
    A[0]->coordinate->push_back(temp4);
    A[0]->coordinate->push_back(temp5);
    A[0]->coordinate->push_back(temp6);
    A[0]->coordinate->push_back(temp7);
    
    A[1]->NameOfType="Road";
    A[1]->coordinate->push_back(temp8);

    
    B[0]->NameOfType="Farm";
        
    B[0]->coordinate->push_back(temp1);
    B[0]->coordinate->push_back(temp3);
    B[0]->coordinate->push_back(temp4);
    B[0]->coordinate->push_back(temp5);
    B[0]->coordinate->push_back(temp6);
    B[0]->coordinate->push_back(temp7);
    B[0]->coordinate->push_back(temp8);
    
    C[0]->NameOfType="City*";
        
    C[0]->coordinate->push_back(temp1);
    C[0]->coordinate->push_back(temp3);
    C[0]->coordinate->push_back(temp4);
    C[0]->coordinate->push_back(temp5);
    C[0]->coordinate->push_back(temp6);
    C[0]->coordinate->push_back(temp7);
    C[0]->coordinate->push_back(temp8);
    
    
    D[0]->NameOfType="Farm";
        
    D[0]->coordinate->push_back(temp1);
    D[0]->coordinate->push_back(temp2);
    D[0]->coordinate->push_back(temp3);
    
    D[1]->NameOfType="Road";
    
    D[1]->coordinate->push_back(temp4);
    D[1]->coordinate->push_back(temp8);
    
    D[2]->NameOfType="Farm";
    D[2]->coordinate->push_back(temp5);
    D[2]->coordinate->push_back(temp7);
    
    D[3]->NameOfType="City";
    D[3]->coordinate->push_back(temp6);
    
    E[0]->NameOfType="Farm"; 
    E[0]->coordinate->push_back(temp1);
    E[0]->coordinate->push_back(temp2);
    E[0]->coordinate->push_back(temp3);
    E[0]->coordinate->push_back(temp5);
    E[0]->coordinate->push_back(temp6);
    E[0]->coordinate->push_back(temp7);
    E[0]->coordinate->push_back(temp8);
    
    E[1]->NameOfType="City";
    E[1]->coordinate->push_back(temp4);
    
    F[0]->NameOfType="Farm"; 
    F[0]->coordinate->push_back(temp4);
    
    F[1]->NameOfType="City*";
    F[1]->coordinate->push_back(temp1);
    F[1]->coordinate->push_back(temp2);
    F[1]->coordinate->push_back(temp3);
    F[1]->coordinate->push_back(temp5);
    F[1]->coordinate->push_back(temp6);
    F[1]->coordinate->push_back(temp7);
    
    
    F[2]->NameOfType="Farm";
    F[2]->coordinate->push_back(temp8);
    
    G[0]->NameOfType="Farm"; 
    G[0]->coordinate->push_back(temp2);
    G[0]->coordinate->push_back(temp1);
    G[0]->coordinate->push_back(temp3);
    
    G[1]->NameOfType="City";
    G[1]->coordinate->push_back(temp4);
    G[1]->coordinate->push_back(temp8);
    G[1]->coordinate->push_back(temp3);
    
    G[2]->NameOfType="Farm";
    G[2]->coordinate->push_back(temp6);
    G[2]->coordinate->push_back(temp7);
    G[2]->coordinate->push_back(temp5);
    
    H[0]->NameOfType="Farm"; 
    H[0]->coordinate->push_back(temp4);
    H[0]->coordinate->push_back(temp8);
    
    H[1]->NameOfType="City";
    H[1]->coordinate->push_back(temp1);
    H[1]->coordinate->push_back(temp2);
    H[1]->coordinate->push_back(temp3);
    
    H[2]->NameOfType="City";
    H[2]->coordinate->push_back(temp5);
    H[2]->coordinate->push_back(temp6);
    H[2]->coordinate->push_back(temp7);
    
    I[0]->NameOfType="Farm"; 
    I[0]->coordinate->push_back(temp4);
    I[0]->coordinate->push_back(temp8);
    
    I[1]->NameOfType="City";
    I[1]->coordinate->push_back(temp1);
    I[1]->coordinate->push_back(temp2);
    I[1]->coordinate->push_back(temp3);
    
    I[2]->NameOfType="City";
    I[2]->coordinate->push_back(temp5);
    I[2]->coordinate->push_back(temp6);
    I[2]->coordinate->push_back(temp7);
    
    J[0]->NameOfType="Farm"; 
    J[0]->coordinate->push_back(temp4);
    J[0]->coordinate->push_back(temp8);
    
    J[1]->NameOfType="City";
    J[1]->coordinate->push_back(temp1);
    J[1]->coordinate->push_back(temp2);
    J[1]->coordinate->push_back(temp3);
    
    J[2]->NameOfType="City";
    J[2]->coordinate->push_back(temp5);
    J[2]->coordinate->push_back(temp6);
    J[2]->coordinate->push_back(temp7);
    
    J[3]->NameOfType="City";
    J[3]->coordinate->push_back(temp5);
    J[3]->coordinate->push_back(temp6);
    J[3]->coordinate->push_back(temp7);
    
}

Tiles::Tiles(const Tiles& orig) {
}

Tiles::~Tiles() {
}

