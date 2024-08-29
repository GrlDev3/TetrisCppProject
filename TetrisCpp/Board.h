/*****************************************************************************************
/* File: Board.h
/* Desc: Board of the game. A matrix of n x n holes.
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
#ifndef _BOARD_
#define _BOARD_

// ----- Includes -----

#include "Pieces.h"

// ----- Defines -----

#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5


// --------------------------------------------------------------------------------
//									 Board
// --------------------------------------------------------------------------------

class Board
{
private:
    enum{POS_FREE, POS_FILLED};
    int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
    Pieces *mPieces;
    int mScreenHeight;

    void InitBoard();
    void DeleteLine(int pY);
    
public:
    Board(Pieces *pPieces, int pScreenHeight);
    ~Board();

    int GetXPosInPixels(int pPos);
    int GetYPosInPixels(int pPos);
    bool IsFreeBlock(int pX, int pY);
    bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);
    void StorePiece(int pX, int pY, int pPiece, int pRotation);
    void DeletePossibleLines();
    bool IsGameOver();
};





#endif