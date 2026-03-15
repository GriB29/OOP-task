#pragma once

#include <string>
#include "Constants.h"

class Board3x3
{
private:

    std::string board[MAX_SIZE][MAX_SIZE];

public:

    int turn;
    bool gameEnded;
    std::string winner;

    Board3x3();

    void reset();

    bool isCellEmpty(int row, int col);

    void makeMove(int row, int col, const std::string& symbol);

    bool checkWin(const std::string& symbol);

    bool isBoardFull();

    std::string getCell(int row,int col) const;
};