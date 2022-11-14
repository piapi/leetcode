#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>

int lastStoneWeightII(vector<int> &stones)
{
    int sum = 0;
    for (int s : stones)
    {
        sum += s;
    }

    int n = stones.size(), m = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (j < stones[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - stones[i]] + stones[i]);
            }
        }
    }
    return sum - 2 * dp[n][m];
}
int main()
{
    vector<int> stones = {31,26,33,21,40};
    cout << lastStoneWeightII(stones);
}