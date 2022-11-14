#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int start = 0;
    int cnt = 0;
    int lenx = matrix.size();
    int leny = matrix[0].size();
    int len = lenx * leny;
    int left = 0, right = leny - 1, top = 0, bot = lenx - 1;
    while (len > 0)
    {
        for (int j = left; j <= right && len > 0; j++)
        {
            res.push_back(matrix[top][j]);
            len--;
        }
        top++;

        for (int i = top; i <= bot && len > 0; i++)
        {
            res.push_back(matrix[i][right]);
            len--;
        }
        right--;

        for (int j = right; j >= left && len > 0; j--)
        {
            res.push_back(matrix[bot][j]);
            len--;
        }
        bot--;
        for (int i = bot; i >= top && len > 0; i--)
        {
            res.push_back(matrix[i][left]);
            len--;
        }
        left++;
    }
    return res;
}
int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = spiralOrder(matrix);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\t";
    }
}
