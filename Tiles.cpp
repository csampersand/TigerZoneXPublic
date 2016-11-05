/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tiles.cpp
 * Author: Charles
 * 
 * Created on November 3, 2016, 11:28 PM
 */
#define NUMBEROFTILES 72;
#include "Tiles.h"
Tiles::Tiles() {
    
//Set the number Copy of tiles allowed in the game    
    const int NUMBEROFTILESPERTYPE[] = {
        2, 4, 1, 4, 5, 2,
        1, 3, 2, 3 ,3 , 3,
        2, 3, 2, 3, 1, 3,
        2, 1, 8, 9, 4, 1
    };
    
    
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
    S[2]=new type();
    S[3]=new type();
    
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
    J[0]->coordinate->push_back(temp1);
    J[0]->coordinate->push_back(temp2);
    J[0]->coordinate->push_back(temp3);
    
    J[1]->NameOfType="City";
    J[1]->coordinate->push_back(temp4);
    
    J[2]->NameOfType="Road";
    J[2]->coordinate->push_back(temp8);
    J[2]->coordinate->push_back(temp6);
    
    J[3]->NameOfType="Farm";
    J[3]->coordinate->push_back(temp5);
    J[3]->coordinate->push_back(temp7);
    
    K[0]->NameOfType="Farm"; 
    K[0]->coordinate->push_back(temp1);
    K[0]->coordinate->push_back(temp2);
    K[0]->coordinate->push_back(temp3);
    
    K[1]->NameOfType="City";
    K[1]->coordinate->push_back(temp6);
    
    K[2]->NameOfType="Road";
    K[2]->coordinate->push_back(temp1);
    K[2]->coordinate->push_back(temp4);
    
    K[3]->NameOfType="Farm";
    K[3]->coordinate->push_back(temp3);
    
    L[0]->NameOfType="Farm"; 
    L[0]->coordinate->push_back(temp3);
    
    L[1]->NameOfType="City";
    L[1]->coordinate->push_back(temp6);
    
    L[2]->NameOfType="Farm";
    L[2]->coordinate->push_back(temp1);
    
    L[3]->NameOfType="Farm";
    L[3]->coordinate->push_back(temp7);
    L[3]->coordinate->push_back(temp5);
    
    L[4]->NameOfType="Road"; 
    L[4]->coordinate->push_back(temp2);
    
    L[5]->NameOfType="Road";
    L[5]->coordinate->push_back(temp4);
    
    L[6]->NameOfType="Road";
    L[6]->coordinate->push_back(temp8);
    
    M[0]->NameOfType="City*";
    M[0]->coordinate->push_back(temp1);
    M[0]->coordinate->push_back(temp2);
    M[0]->coordinate->push_back(temp3);
    M[0]->coordinate->push_back(temp4);

    M[1]->NameOfType="Farm";
    M[1]->coordinate->push_back(temp5);
    M[1]->coordinate->push_back(temp6);
    M[1]->coordinate->push_back(temp7);
    M[1]->coordinate->push_back(temp8);
    
    N[0]->NameOfType="City";
    N[0]->coordinate->push_back(temp1);
    N[0]->coordinate->push_back(temp2);
    N[0]->coordinate->push_back(temp3);
    N[0]->coordinate->push_back(temp4);

    N[1]->NameOfType="Farm";
    N[1]->coordinate->push_back(temp5);
    N[1]->coordinate->push_back(temp6);
    N[1]->coordinate->push_back(temp7);
    N[1]->coordinate->push_back(temp8);
     
    O[0]->NameOfType="City*";
    O[0]->coordinate->push_back(temp2);
    O[0]->coordinate->push_back(temp3);
    O[0]->coordinate->push_back(temp4);

    O[1]->NameOfType="Farm";
    O[1]->coordinate->push_back(temp7);
    
    O[2]->NameOfType="Farm";
    O[2]->coordinate->push_back(temp1);
    O[2]->coordinate->push_back(temp5);
    
    O[3]->NameOfType="Road";
    O[3]->coordinate->push_back(temp6);
    O[3]->coordinate->push_back(temp8);
    
    P[0]->NameOfType="City";
    P[0]->coordinate->push_back(temp2);
    P[0]->coordinate->push_back(temp3);
    P[0]->coordinate->push_back(temp4);

    P[1]->NameOfType="Farm";
    P[1]->coordinate->push_back(temp7);
    
    P[2]->NameOfType="Farm";
    P[2]->coordinate->push_back(temp1);
    P[2]->coordinate->push_back(temp5);
    
    P[3]->NameOfType="Road";
    P[3]->coordinate->push_back(temp6);
    P[3]->coordinate->push_back(temp8);
    
    Q[0]->NameOfType="City*";
        
    Q[0]->coordinate->push_back(temp1);
    Q[0]->coordinate->push_back(temp2);
    Q[0]->coordinate->push_back(temp3);
    Q[0]->coordinate->push_back(temp4);
    Q[0]->coordinate->push_back(temp5);
    Q[0]->coordinate->push_back(temp6);
    Q[0]->coordinate->push_back(temp7);
    
    Q[1]->NameOfType="Farm";
    Q[1]->coordinate->push_back(temp8);
    
    R[0]->NameOfType="City";    
    R[0]->coordinate->push_back(temp1);
    R[0]->coordinate->push_back(temp2);
    R[0]->coordinate->push_back(temp3);
    R[0]->coordinate->push_back(temp4);
    R[0]->coordinate->push_back(temp5);
    R[0]->coordinate->push_back(temp6);
    R[0]->coordinate->push_back(temp7);
    
    R[1]->NameOfType="Farm";
    R[1]->coordinate->push_back(temp8);
    
    S[0]->NameOfType="City*";
    S[0]->coordinate->push_back(temp2);
    S[0]->coordinate->push_back(temp3);
    S[0]->coordinate->push_back(temp4);
    S[0]->coordinate->push_back(temp5);
    S[0]->coordinate->push_back(temp6);

    S[1]->NameOfType="Farm";
    S[1]->coordinate->push_back(temp7);
    
    S[2]->NameOfType="Farm";
    S[2]->coordinate->push_back(temp1);
    
    S[3]->NameOfType="Road";
    S[3]->coordinate->push_back(temp8);
    
    T[0]->NameOfType="City";
    T[0]->coordinate->push_back(temp2);
    T[0]->coordinate->push_back(temp3);
    T[0]->coordinate->push_back(temp4);
    T[0]->coordinate->push_back(temp5);
    T[0]->coordinate->push_back(temp6);

    T[1]->NameOfType="Farm";
    T[1]->coordinate->push_back(temp7);
    
    T[2]->NameOfType="Farm";
    T[2]->coordinate->push_back(temp1);
    
    T[3]->NameOfType="Road";
    T[3]->coordinate->push_back(temp8);
    
    U[0]->NameOfType="Farm";
        
    U[0]->coordinate->push_back(temp1);
    U[0]->coordinate->push_back(temp2);
    U[0]->coordinate->push_back(temp3);
    
    U[1]->NameOfType="Road";
    
    U[1]->coordinate->push_back(temp4);
    U[1]->coordinate->push_back(temp8);
    
    U[2]->NameOfType="Farm";
    U[2]->coordinate->push_back(temp5);
    U[2]->coordinate->push_back(temp6);
    U[2]->coordinate->push_back(temp7);
    
    V[0]->NameOfType="Farm";
    V[0]->coordinate->push_back(temp3);
    V[0]->coordinate->push_back(temp4);
    V[0]->coordinate->push_back(temp5);
    V[0]->coordinate->push_back(temp6);
    V[0]->coordinate->push_back(temp7);
    
    V[1]->NameOfType="Road";
    V[1]->coordinate->push_back(temp2);
    V[1]->coordinate->push_back(temp8);
    
    V[2]->NameOfType="Farm";
    V[2]->coordinate->push_back(temp1);
    
    W[0]->NameOfType="Road"; 
    W[0]->coordinate->push_back(temp2);
    
    W[1]->NameOfType="Road";
    W[1]->coordinate->push_back(temp8);
    
    W[2]->NameOfType="Road";
    W[2]->coordinate->push_back(temp6);
    
    W[3]->NameOfType="Farm";
    W[3]->coordinate->push_back(temp3);
    W[3]->coordinate->push_back(temp4);
    W[3]->coordinate->push_back(temp5);
    
    W[4]->NameOfType="Farm"; 
    W[4]->coordinate->push_back(temp1);
    
    W[5]->NameOfType="Farm";
    W[5]->coordinate->push_back(temp7);
    
    X[0]->NameOfType="Road"; 
    X[0]->coordinate->push_back(temp2);
    
    X[1]->NameOfType="Road";
    X[1]->coordinate->push_back(temp6);
    
    X[2]->NameOfType="Road";
    X[2]->coordinate->push_back(temp8);
    
    X[3]->NameOfType="Road";
    X[3]->coordinate->push_back(temp4);
    
    X[4]->NameOfType="Farm"; 
    X[4]->coordinate->push_back(temp1);
    
    X[5]->NameOfType="Farm";
    X[5]->coordinate->push_back(temp3);

    X[6]->NameOfType="Farm";
    X[6]->coordinate->push_back(temp5);
    
    X[7]->NameOfType="Farm";
    X[7]->coordinate->push_back(temp7);
    
    int NumberOfTiles=NUMBEROFTILES;
    

}

Tiles::Tiles(const Tiles& orig) {
}

Tiles::~Tiles() {
}

