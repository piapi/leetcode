#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
vector<vector<string>> res;

bool idValid(int row, int col, vector<string> &path)
{
    // 判断列
    for (int i = 0; i < row; i++)
    {
        if (path[i][col] == 'Q')
        {
            return false;
        }
    }
    //判断斜着
    for (int i = path.size()-1; i >= 0; i--)
    {
        for (int j = path.size()-1;; j >= 0; j--)
        {
            if (path[i][j] == 'Q' && (abs(i - row) == abs(j - col)))
            {
                return false;
            }
        }
    }
    return true;
}
void back(int n, int row, vector<string> &path)
{
    if (row == n)
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (idValid(row, i, path))
        {
            path[row][i] = 'Q';
            back(n, row + 1, path);
            path[row][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<string> path(n, string(n, '.'));
    back(n, 0, path);
    return res;
}
int main()
{
    vector<vector<string>> xx = solveNQueens(4);
}