#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
vector<int> path;
vector<vector<int>> res;

void back(vector<int> &nums, int idx)
{
    if (path.size() > 1)
    {
        res.push_back(path);
    }
    unordered_set<int> usedS;
    for (int i = idx; i < nums.size(); i++)
    {
        if ((!path.empty() && nums[i] < path.back()) || usedS.count(nums[i])>0)
        {
            continue;
        }
        usedS.insert(nums[i]);
        path.push_back(nums[i]);
        back(nums, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    back(nums, 0);
    return res;
}
int main()
{
}