#pragma once
#include <string>

class GameBoard
{
public:

    virtual ~GameBoard() {};

    virtual void reset() = 0;

    virtual bool isCellEmpty(int row,int col) = 0;

    virtual void makeMove(int row,int col,const std::string& symbol) = 0;

    virtual bool isBoardFull() = 0;

};