#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
vector<vector<string>> res;
bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    // row
    for (int i = 0; i < 9; i++)
    {
        if (c == board[row][i])
        {
            return false;
        }
    }
    // col
    for (int i = 0; i < 9; i++)
    {
        if (c == board[i][col])
        {
            return false;
        }
    }
    //九宫格
    int xx=3 * (row / 3);
    int yy=3 * (col / 3);
    for (int i = xx; i < xx + 3; i++)
    {
        for (int j = yy; j < yy + 3; j++)
        {
            if (board[i][j] == c)
            {
                return false;
            }
        }
    }
    return true;
}
bool back(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                continue;
            }
            for (char c = '1'; c <= '9'; c++)
            {
                if (isValid(board, i, j, c))
                {
                    cout<<c<<endl;
                    board[i][j] = c;
                    if (back(board))
                    {
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    back(board);
}
int main()
{
}