#pragma once

#include <string>
#include "Constants.h"

class Board4x4
{
private:

    std::string board[MAX_SIZE_4][MAX_SIZE_4];

public:

    int turn;
    bool gameEnded;
    std::string winner;

    Board4x4();

    void reset();

    bool isCellEmpty(int row,int col);

    void makeMove(int row,int col,const std::string& symbol);

    bool checkWin3(const std::string& symbol);

    bool isBoardFull();

    std::string getCell(int row,int col) const;

};