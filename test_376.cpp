#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int wiggleMaxLength(vector<int> &nums)
{
    int res = 1;
    int pre = 0;
    int cur = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        cur = nums[i + 1] - nums[i];
        if ((cur > 0 && pre <= 0) || (cur < 0 && pre >= 0))
        {
            pre = cur;
            res++;
        }
    }
    return res;
}
int main()
{
}