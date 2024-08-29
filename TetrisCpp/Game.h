/*****************************************************************************************
/* File: Game.h
/* Desc: General class for the game
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

#ifndef _GAME_
#define _GAME_

// ------ Includes -----
#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>

// ------ Defines -----
#define WAIT_TIME 700   //Number of milliseconds that the piece remains before going 1 block down

// --------------------------------------------------------------------------------
//									 Game
// --------------------------------------------------------------------------------

class Game
{
private:
    int mScreenHeight; //Screen height in pixels
    int mNextPosX, mNextPosY; //Position of the next piece
    int mNextPiece, mNextRotation; //Type and rotation of the next piece

    Board * mBoard;
    Pieces * mPieces;
    IO * mIO;

    int GetRand(int pA, int pB);
    void InitGame();
    void DrawPiece (int pX, int pY, int pPiece, int pRotation);
    void DrawBoard ();
public:
    int mPosX, mPosY; // Position of the piece that is falling down
    int mPiece, mRotation; //Type and rotation of the piece that is falling down

    Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight); 
    ~Game();
    void DrawScene();
    void CreateNewPiece();
    
};





#endif // _GAME_