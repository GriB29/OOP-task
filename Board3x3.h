#pragma once

#include "GameBoard.h"
#include "Constants.h"
#include <string>

class Board3x3 : public GameBoard
{
private:

    std::string board[MAX_SIZE][MAX_SIZE];

public:

    int turn;
    bool gameEnded;
    std::string winner;

    Board3x3();

    void reset() override;

    bool isCellEmpty(int row,int col) override;

    void makeMove(int row,int col,const std::string& symbol) override;

    bool isBoardFull() override;

    bool checkWin(const std::string& symbol);

    std::string getCell(int row,int col) const;

};