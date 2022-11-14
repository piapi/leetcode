#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    // 0卖出
    // 1买入
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        cout<<dp[i][0]<<"\t"<<dp[i][1]<<endl;
    }
    return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
}
int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(nums);
}