/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tiles.h
 * Author: ninou14fr
 *
 * Created on November 3, 2016, 11:28 PM
 */

#ifndef TILES_H
#include <vector>
#include <string>
#include <iostream>
#define TILES_H

class Tiles {
public:
    Tiles();
    struct Coordinate
    {
            std::string NameOfCoordinate;
    };
    struct type{
        std::string NameOfType;
        std::vector<Coordinate> *coordinate=new std::vector<Coordinate>();
    };
    type *A[2];
    type *B[1];
    type *C[1];
    type *D[4];
    type *E[2];
    type *F[3];
    type *G[3];
    type *H[3];
    type *I[3];
    type *J[4];
    type *K[4];
    type *L[7];
    type *M[2];
    type *N[2];
    type *O[4];
    type *P[4];
    type *Q[2];
    type *R[2];
    type *S[4];
    type *T[4];
    type *U[3];
    type *V[3];
    type *W[6];
    type *X[8];
    Tiles(const Tiles& orig);
    virtual ~Tiles();
private:
    
};

#endif /* TILES_H */

