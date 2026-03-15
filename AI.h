#pragma once

#include "Board3x3.h"
#include "Board4x4.h"

class AI
{
public:

    static void computerMove3x3(
        Board3x3& board,
        const std::string& computerSymbol,
        const std::string& playerSymbol
    );

    static void computerMove4x4(
        Board4x4& board,
        const std::string& computerSymbol,
        const std::string& player1Symbol,
        const std::string& player2Symbol
    );

};