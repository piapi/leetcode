#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> res;
    if (nums.size() < 3)
    {
        /* code */
        return res;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
        /* code */
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // 去重
        int temp = -nums[i];
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right && left < nums.size())
        {
            /* code */
            if (nums[left] + nums[right] == temp)
            {
                /* code */
                vector<int> a = {nums[i], nums[left], nums[right]};
                res.push_back(a);
                left++;
                right--; 
                while (left < right && nums[left] == nums[left - 1])
                    left++; // 去重
                while (left < right && nums[right] == nums[right + 1])
                    right--; // 去重
            }
            else if (nums[left] + nums[right] < temp)
            {
                /* code */
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> res;
    vector<int> nums = {0,0,0,0};
    res = threeSum(nums);
    cout << "sad";
}