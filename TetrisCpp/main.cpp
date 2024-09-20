/** Tetris game tutorial from Javier López
 * https://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/
 *****************************************************************************************
/* 
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

#include "Game.h"
#ifndef LINUX
#include <windows.h>
#endif

#ifndef LINUX
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
#else
int main()  //for Linux users
#endif
{
    // ---- Vars ----

    //Class for drawing, it uses SDL for the rendering. To use a different renderer change the methods of this class.

    IO mIOmain;
    int mScreenHeightMain = mIOmain.GetScreenHeight();

    //Pieces
    Pieces mPiecesMain;

    //Board
    Board mBoardMain (&mPiecesMain, mScreenHeightMain);

    //Game
    Game mGameMain (&mBoardMain, &mPiecesMain, &mIOmain, mScreenHeightMain);

    //Get the actual clock milliseconds(SDL)
    unsigned long mTime1 = SDL_GetTicks();


    // ---- Main Loop ----

    while (!mIOmain.IsKeyDown(SDLK_ESCAPE))
    {
        // ---- Draw Frame ----

        mIOmain.ClearScreen(); //Clear screen
        mGameMain.DrawScene(); //Draw
        mIOmain.UpdateScreen(); //Put the graphic context in the screen

        // ---- Input ----
        int mKey = mIOmain.Pollkey();
        switch (mKey)
        {
        case (SDLK_RIGHT):
            if (mBoardMain.IsPossibleMovement(mGameMain.mPosX + 1, mGameMain.mPosY, mGameMain.mPiece, mGameMain.mRotation))
                mGameMain.mPosX++;
            break;

        case(SDLK_LEFT):
            if (mBoardMain.IsPossibleMovement(mGameMain.mPosX - 1, mGameMain.mPosY, mGameMain.mPiece, mGameMain.mRotation))
                mGameMain.mPosX--;
            break;

        case(SDLK_DOWN):
            if (mBoardMain.IsPossibleMovement(mGameMain.mPosX, mGameMain.mPosY + 1, mGameMain.mPiece, mGameMain.mRotation))
                mGameMain.mPosY++;
            break;

        case(SDLK_x):
        {
            //Check collision from up to down
            while (mBoardMain.IsPossibleMovement(mGameMain.mPosX, mGameMain.mPosY, mGameMain.mPiece, mGameMain.mRotation))
                mGameMain.mPosY++;

            mBoardMain.StorePiece(mGameMain.mPosX, mGameMain.mPosY - 1, mGameMain.mPiece, mGameMain.mRotation);
            mBoardMain.DeletePossibleLines();

            if (mBoardMain.IsGameOver())
            {
                mIOmain.Getkey();
                exit(0);
            }
            mGameMain.CreateNewPiece();
            break;
        }
            
        case (SDLK_z): 
            if (mBoardMain.IsPossibleMovement(mGameMain.mPosX, mGameMain.mPosY, mGameMain.mPiece, (mGameMain.mRotation + 1) % 4))
                mGameMain.mRotation = (mGameMain.mRotation + 1) % 4;
            break;
        
        }

        // ---- Vertical movement ----
        unsigned long mTime2 = SDL_GetTicks();

        if ((mTime2 - mTime1) > WAIT_TIME)
        {
            if (mBoardMain.IsPossibleMovement(mGameMain.mPosX, mGameMain.mPosY + 1, mGameMain.mPiece, mGameMain.mRotation)) {
                mGameMain.mPosY++;
            }
            else
            {
                mBoardMain.StorePiece(mGameMain.mPosX, mGameMain.mPosY, mGameMain.mPiece, mGameMain.mRotation);
                mBoardMain.DeletePossibleLines();

                if (mBoardMain.IsGameOver())
                {
                    mIOmain.Getkey();
                    exit(0);
                }
                mGameMain.CreateNewPiece();
            }
            mTime1 = SDL_GetTicks();
        }

    }
    

    return 0;
} 