#include "AI.h"
#include "Constants.h"

static bool checkWin3x3(std::string arr[][MAX_SIZE], const std::string& symbol)
{
    for(int i=0;i<MAX_SIZE;i++)
        if(arr[i][0]==symbol && arr[i][1]==symbol && arr[i][2]==symbol)
            return true;

    for(int j=0;j<MAX_SIZE;j++)
        if(arr[0][j]==symbol && arr[1][j]==symbol && arr[2][j]==symbol)
            return true;

    if(arr[0][0]==symbol && arr[1][1]==symbol && arr[2][2]==symbol)
        return true;

    if(arr[2][0]==symbol && arr[1][1]==symbol && arr[0][2]==symbol)
        return true;

    return false;
}

void AI::computerMove3x3(
    Board3x3& board,
    const std::string& computerSymbol,
    const std::string& playerSymbol
)
{
    std::string arr[MAX_SIZE][MAX_SIZE];

    for(int i=0;i<MAX_SIZE;i++)
        for(int j=0;j<MAX_SIZE;j++)
            arr[i][j]=board.getCell(i,j);

    for(int i=0;i<MAX_SIZE;i++)
        for(int j=0;j<MAX_SIZE;j++)
            if(arr[i][j]==" ")
            {
                arr[i][j]=computerSymbol;

                if(checkWin3x3(arr,computerSymbol))
                {
                    board.makeMove(i,j,computerSymbol);
                    return;
                }

                arr[i][j]=" ";
            }

    for(int i=0;i<MAX_SIZE;i++)
        for(int j=0;j<MAX_SIZE;j++)
            if(arr[i][j]==" ")
            {
                arr[i][j]=playerSymbol;

                if(checkWin3x3(arr,playerSymbol))
                {
                    board.makeMove(i,j,computerSymbol);
                    return;
                }

                arr[i][j]=" ";
            }

    if(board.isCellEmpty(1,1))
    {
        board.makeMove(1,1,computerSymbol);
        return;
    }

    int corners[4][2]={{0,0},{0,2},{2,0},{2,2}};

    for(auto& c:corners)
    {
        if(board.isCellEmpty(c[0],c[1]))
        {
            board.makeMove(c[0],c[1],computerSymbol);
            return;
        }
    }

    for(int i=0;i<MAX_SIZE;i++)
        for(int j=0;j<MAX_SIZE;j++)
            if(board.isCellEmpty(i,j))
            {
                board.makeMove(i,j,computerSymbol);
                return;
            }
}

static bool checkWin3InRow(
    std::string arr[][MAX_SIZE_4],
    int size,
    const std::string& symbol
)
{
    for(int i=0;i<size;i++)
        for(int j=0;j<=size-3;j++)
            if(arr[i][j]==symbol &&
               arr[i][j+1]==symbol &&
               arr[i][j+2]==symbol)
                return true;

    for(int j=0;j<size;j++)
        for(int i=0;i<=size-3;i++)
            if(arr[i][j]==symbol &&
               arr[i+1][j]==symbol &&
               arr[i+2][j]==symbol)
                return true;

    for(int i=0;i<=size-3;i++)
        for(int j=0;j<=size-3;j++)
            if(arr[i][j]==symbol &&
               arr[i+1][j+1]==symbol &&
               arr[i+2][j+2]==symbol)
                return true;

    for(int i=2;i<size;i++)
        for(int j=0;j<=size-3;j++)
            if(arr[i][j]==symbol &&
               arr[i-1][j+1]==symbol &&
               arr[i-2][j+2]==symbol)
                return true;

    return false;
}

void AI::computerMove4x4(
    Board4x4& board,
    const std::string& computerSymbol,
    const std::string& player1,
    const std::string& player2
)
{
    std::string arr[MAX_SIZE_4][MAX_SIZE_4];

    for(int i=0;i<MAX_SIZE_4;i++)
        for(int j=0;j<MAX_SIZE_4;j++)
            arr[i][j]=board.getCell(i,j);

    int size=MAX_SIZE_4;

    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(arr[i][j]==" ")
            {
                arr[i][j]=computerSymbol;

                if(checkWin3InRow(arr,size,computerSymbol))
                {
                    board.makeMove(i,j,computerSymbol);
                    return;
                }

                arr[i][j]=" ";
            }

    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(arr[i][j]==" ")
            {
                arr[i][j]=player1;

                if(checkWin3InRow(arr,size,player1))
                {
                    board.makeMove(i,j,computerSymbol);
                    return;
                }

                arr[i][j]=" ";
            }

    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(arr[i][j]==" ")
            {
                arr[i][j]=player2;

                if(checkWin3InRow(arr,size,player2))
                {
                    board.makeMove(i,j,computerSymbol);
                    return;
                }

                arr[i][j]=" ";
            }

    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(board.isCellEmpty(i,j))
            {
                board.makeMove(i,j,computerSymbol);
                return;
            }
}

