#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
vector<int> path;
int curSum = 0;
vector<vector<int>> res;

void back(vector<int> &nums, int idx, vector<bool> &used)
{
    res.push_back(path);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
        {
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        back(nums, i + 1, used);
        used[i] = false;
        path.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    vector<bool> used(nums.size(), false);
    back(nums, 0, used);
    return res;
}
int main()
{
}