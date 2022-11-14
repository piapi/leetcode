#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    unordered_map<int, int> ump;
    if (nums.size() < 4)
    {
        return res;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                long int tt = nums[i] + nums[j];
                tt += nums[left];
                tt += nums[right];
                if (tt < target)
                {
                    left++;
                }
                else if (tt > target)
                {
                    right--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                    res.push_back(temp);
                    left++;
                    right--;
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
            }
        }
    }
    return res;
}
int main()
{
    vector<int> n = {1000000000, 1000000000, 1000000000, 1000000000};
    vector<vector<int>> res = fourSum(n, 4000000000);
    for (int i = 0; i < res.size(); i++)
    {
        for (int r : res[i])
        {
            cout << r << "\t";
        }
        cout << endl;
    }
}