/*****************************************************************************************
/* File: Pieces.cpp
/* Desc: All the Tetris pieces with their respective rotations and displacements for the hotspot
/*
/* gametuto.com - Javier L�pez L�pez (javilop.com)
/*
/*****************************************************************************************
/*
/* Creative Commons - Attribution 3.0 Unported
/* You are free:
/*	to Share � to copy, distribute and transmit the work
/*	to Remix � to adapt the work
/*
/* Under the following conditions:
/* Attribution. You must attribute the work in the manner specified by the author or licensor 
/* (but not in any way that suggests that they endorse you or your use of the work).
/*
/*****************************************************************************************/

#include "Pieces.h"

    //Definition of Piece information
    char mPieceInfo[7][4][5][5] = {
        // Square shape
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}}},
        // I shape
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 1},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {1, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}}},
        // L shape
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 1, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}}},
        // L shape mirrored
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 1, 0},
             {0, 0, 0, 0, 0}}},
        // N shape
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 1, 0, 0, 0},
             {0, 0, 0, 0, 0}},

            {{0, 0, 0, 0, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}}},
        // N shape mirrored
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 0, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}}},
        // T shape
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}}}};

    //displacement of the piece to the position where it is first drawn in the board when it is created
    char mPieceInitPos[7][4][2] = {
        // Square shape
        {{-2, -3}, 
        {-2, -3},
        {-2, -3},
        {-2, -3}},
        // I shape
        {{-2, -2},
        {-2, -3},
        {-2, -2},
        {-2, -3}},
        // L shape
        {{-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}},
        // L shape mirrored
        {{-2, -3},
        {-2, -2},
        {-2, -3},
        {-2, -3}},
        // N shape
        {{-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}},
        // N shape mirrored
        {{-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}},
        // T shape
        {{-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}}
    };

    /// @brief GetBlockType
    /// @param pPiece piece to draw
    /// @param pRotation 1 of the 4 possible rotations
    /// @param pX horizontal position in blocks
    /// @param pY vertical position in blocks
    /// @return type of a block(0 = no block, 1 = normal block, 2 = pivot block)
    int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY){
        return mPieceInfo[pPiece][pRotation][pX][pY];
    }

    /// @brief GetXInitPos
    /// @param pPiece piece to draw
    /// @param pRotation 1 of the 4 possible rotations
    /// @return the horizontal displacement of the piece that has to be applied in order to create it in the correct position
    int Pieces::GetXInitPos(int pPiece, int pRotation){
        return mPieceInitPos[pPiece][pRotation][0];
    }

    /// @brief GetYInitPos
    /// @param pPiece piece to draw
    /// @param pRotation 1 of the 4 possible rotations
    /// @return the vertical displacement of the piece that has to be applied in order to create it in the correct position.
    int Pieces::GetYInitPos(int pPiece, int pRotation){
        return mPieceInitPos[pPiece][pRotation][1];
    }
    



