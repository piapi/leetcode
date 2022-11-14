#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
vector<int> path;
vector<vector<int>> res;

void back(vector<int> &nums, int idx, vector<bool> &used)
{
    if (path.size() == nums.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if ((i>0 && (nums[i] == nums[i - 1]) && !used[i - 1]) || used[i])
        {
            continue;
        }
        
        used[i] = true;
        path.push_back(nums[i]);
        back(nums, 0, used);
        used[i] = false;
        path.pop_back();
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<bool> uesd(nums.size(), false);
    back(nums, 0, uesd);
    return res;
}
int main()
{
}