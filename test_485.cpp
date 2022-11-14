#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int left = 0;
    int res = 0;
    int flag = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        if (nums[i] != 1)
        {
            left = i + 1;
        }

        res = max(res, i - left + 1);

        
    }
    return res;
}
int main()
{
    vector<int> n = {0};
    cout << findMaxConsecutiveOnes(n);
}