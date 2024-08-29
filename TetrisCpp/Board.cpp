/*****************************************************************************************
/* File: Board.cpp
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

// ----- Includes -----
#include "Board.h"

/**/

/// @brief Board class constructor.
/// @param pPieces 
/// @param pScreenHeight 
Board::Board(Pieces *pPieces, int pScreenHeight)
{
    //Get the screen height
    mScreenHeight = pScreenHeight;

    //Get the pointer to the pieces class
    mPieces = pPieces;

    //Init the board blocks with free positions
    InitBoard();
}

Board::~Board()
{
}

/// @brief Nested loop for initializing the board blocks with free positions.
void Board::InitBoard()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            mBoard[i][j] = POS_FREE;
        }
        
    }
    
}

/// @brief Erases a line of the board by moving all above lines down
/// @param pY Vertical position in blocks of the line to erase
void Board::DeleteLine(int pY)
{
    for (int y = pY; y > 0; y--)
    {
        for (int i = 0; i < BOARD_WIDTH; i++)
        {
            mBoard[i][y] = mBoard[i][y-1];
        }
        
    }
    
}

/// @brief Specification of the block's horizontal position in pixels
/// @param pPos Horizontal position of the block in the board
/// @return the horizontal position (in pixels) of the block
int Board::GetXPosInPixels(int pPos)
{
    return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH/2))) + (pPos * BLOCK_SIZE));
}

/// @brief Specification of the block's vertical position in pixels
/// @param pPos Horizontal position of the block in the board
/// @return the vertical position (in pixels) of the block
int Board::GetYPosInPixels(int pPos)
{
    return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}

/// @brief Checks if a board block is filled or not
/// @param pX Horizontal position in blocks
/// @param pY Vertical position in blocks
/// @return true(current block is empty) or false (current block is filled)
bool Board::IsFreeBlock(int pX, int pY)
{
    if (mBoard[pX][pY] == POS_FREE)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

/// @brief Checks if the piece can be stored at this position without any collision
/// @param pX Horizontal position in blocks
/// @param pY Vertical position in blocks
/// @param pPiece Piece to draw
/// @param pRotation 1 of the 4 possible rotations
/// @return true(movement is possible) or false (movement is not possible)
bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation)
{
    //Checks collision with piece already stored in the board or the board limits
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            //Check if the piece is outside the limits of the board
            if(i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1)
            {
                if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
                {
                    return false;
                }
                
            }

            //Check if the piece have collisioned with a block already stored in the map
            if (j1 >= 0)
            {
                if ((mPieces->GetBlockType(pPiece, pRotation, j2,i2) != 0) && (!IsFreeBlock(i1,j1)))
                {
                    return false;
                }
                
            }
            
        }
        
    }

    //No collision
    return true;
    
}

/// @brief Fills appropriate block in the board to store a piece, using a nested loop.
/// @param pX Horizontal position in blocks
/// @param pY Vertical position in blocks
/// @param pPiece Piece to draw
/// @param pRotation 1 of the 4 possible rotations
void Board::StorePiece(int pX, int pY, int pPiece, int pRotation)
{
    //Store each block of the piece into the board
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)   
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            //Store only the blocks of the piece that are not holes
            if(mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
            {
                mBoard[i1][j1] = POS_FILLED;
            }
        }
        
    }
    
}

/// @brief Erases all line that should be removed
void Board::DeletePossibleLines()
{
    for (int j = 0; j < BOARD_HEIGHT; j++)
    {
        //Checks if a line has all their horizontal blocks filled
        int i = 0;
        while (i < BOARD_WIDTH)
        {
            if(mBoard[i][j] != POS_FILLED)
                break;
            i++;
        }

        //Then that line gets erased, and all upper lines get moved down one row
        if (i == BOARD_WIDTH)
        {
            DeleteLine(j);
        }
        
        
    }
    
}

/// @brief Checks if there are blocks in the first row, which means the end of the game.
/// @return true(ended) or false(on-going)
bool Board::IsGameOver()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if(mBoard[i][0] == POS_FILLED)
            return true;
    }

    return false;
    
}