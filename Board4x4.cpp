#include "Board4x4.h"

Board4x4::Board4x4()
{
    reset();
}

void Board4x4::reset()
{
    for(int i=0;i<MAX_SIZE_4;i++)
        for(int j=0;j<MAX_SIZE_4;j++)
            board[i][j]=" ";

    turn=1;
    gameEnded=false;
    winner="";
}

bool Board4x4::isCellEmpty(int row,int col)
{
    return board[row][col]==" ";
}

void Board4x4::makeMove(int row,int col,const std::string& symbol)
{
    if(isCellEmpty(row,col))
        board[row][col]=symbol;
}

bool Board4x4::checkWin3(const std::string& symbol)
{
    int size=MAX_SIZE_4;

    for(int i=0;i<size;i++)
        for(int j=0;j<=size-3;j++)
            if(board[i][j]==symbol &&
               board[i][j+1]==symbol &&
               board[i][j+2]==symbol)
                return true;

    for(int j=0;j<size;j++)
        for(int i=0;i<=size-3;i++)
            if(board[i][j]==symbol &&
               board[i+1][j]==symbol &&
               board[i+2][j]==symbol)
                return true;

    for(int i=0;i<=size-3;i++)
        for(int j=0;j<=size-3;j++)
            if(board[i][j]==symbol &&
               board[i+1][j+1]==symbol &&
               board[i+2][j+2]==symbol)
                return true;

    for(int i=2;i<size;i++)
        for(int j=0;j<=size-3;j++)
            if(board[i][j]==symbol &&
               board[i-1][j+1]==symbol &&
               board[i-2][j+2]==symbol)
                return true;

    return false;
}

bool Board4x4::isBoardFull()
{
    for(int i=0;i<MAX_SIZE_4;i++)
        for(int j=0;j<MAX_SIZE_4;j++)
            if(board[i][j]==" ")
                return false;

    return true;
}

std::string Board4x4::getCell(int row,int col) const
{
    return board[row][col];
}