#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
vector<int> searchRange(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    vector<int> res = {-1, -1};
    if (nums.size()<1)
    {
        /* code */
        return res;
    }
    
    while (true)
    {
        if (nums[left] < target)
        {
            /* code */
            left++;
        }
        if (nums[right] > target)
        {
            /* code */
            right--;
        }
        if (left > right || left >= nums.size() || right < 0)
        {
            /* code */
            break;
        }
        if (nums[left] == target && nums[right] == target)
        {
            /* code */
            res[0] = left;
            res[1] = right;
            break;
        }
    }
    return res;
}
int main()
{
    vector<int> xx = {};
    vector<int> res = searchRange(xx, 5);
    for (size_t i = 0; i < res.size(); i++)
    {
        /* code */
        cout << res[i] << endl;
    }
}