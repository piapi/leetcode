#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    cout<<matrix.size()*matrix[0].size();
    int i = 0;
    int j = 0;
    int loop = 0;
    int start = 0;
    int cnt = 1;
    while (loop < n / 2)
    {
        for (j = start; j < n - loop - 1; j++)
        {
            // cout << i << "\t" << j << "\t" << cnt << endl;
            matrix[i][j] = cnt++;
        }
        for (i = start; i < n - loop - 1; i++)
        {
            // cout << i << "\t" << j << "\t" << cnt << endl;
            matrix[i][j] = cnt++;
        }
        for (; j > loop; j--)
        {
            // cout << i << "\t" << j << "\t" << cnt << endl;
            matrix[i][j] = cnt++;
        }
        for (; i > loop; i--)
        {
            // cout << i << "\t" << j << "\t" << cnt << endl;
            matrix[i][j] = cnt++;
        }
        loop++;
        start++;
        i++;
    }
    if (n % 2)
    {
        matrix[start][start] = n * n;
    }

    return matrix;
}
int main()
{
    int n = 2;
    vector<vector<int>> matrix = generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}