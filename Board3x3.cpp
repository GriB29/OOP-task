#include "Board3x3.h"

Board3x3::Board3x3()
{
    reset();
}

void Board3x3::reset()
{
    for(int i=0;i<MAX_SIZE;i++)
        for(int j=0;j<MAX_SIZE;j++)
            board[i][j] = " ";

    turn = 1;
    gameEnded = false;
    winner = "";
}

bool Board3x3::isCellEmpty(int row,int col)
{
    return board[row][col] == " ";
}

void Board3x3::makeMove(int row,int col,const std::string& symbol)
{
    if(isCellEmpty(row,col))
        board[row][col] = symbol;
}

bool Board3x3::isBoardFull()
{
    for(int i=0;i<MAX_SIZE;i++)
        for(int j=0;j<MAX_SIZE;j++)
            if(board[i][j] == " ")
                return false;

    return true;
}

bool Board3x3::checkWin(const std::string& symbol)
{
    for(int i=0;i<MAX_SIZE;i++)
        if(board[i][0]==symbol &&
           board[i][1]==symbol &&
           board[i][2]==symbol)
            return true;

    for(int j=0;j<MAX_SIZE;j++)
        if(board[0][j]==symbol &&
           board[1][j]==symbol &&
           board[2][j]==symbol)
            return true;

    if(board[0][0]==symbol &&
       board[1][1]==symbol &&
       board[2][2]==symbol)
        return true;

    if(board[2][0]==symbol &&
       board[1][1]==symbol &&
       board[0][2]==symbol)
        return true;

    return false;
}

std::string Board3x3::getCell(int row,int col) const
{
    return board[row][col];
}