#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
// 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

bool containsNearbyDuplicate(vector<int> &nums, int k)
{

    unordered_map<int, int> dictionary;
    int length = nums.size();
    for (int i = 0; i < length; i++)
    {
        int num = nums[i];
        if (dictionary.count(num) && i - dictionary[num] <= k)
        {
            return true;
        }
        dictionary[num] = i;
    }
    return false;
}
int main()

{
    vector<int> xx = {1, 2, 3, 1};

    cout << containsNearbyDuplicate(xx, 3);
}