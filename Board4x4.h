#pragma once

#include "GameBoard.h"
#include "Constants.h"
#include <string>

class Board4x4 : public GameBoard
{
private:

    std::string board[MAX_SIZE_4][MAX_SIZE_4];

public:

    int turn;
    bool gameEnded;
    std::string winner;

    Board4x4();

    void reset() override;

    bool isCellEmpty(int row,int col) override;

    void makeMove(int row,int col,const std::string& symbol) override;

    bool isBoardFull() override;

    bool checkWin3(const std::string& symbol);

    std::string getCell(int row,int col) const;

};