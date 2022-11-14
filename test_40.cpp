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

void back(vector<int> &candidates, int target, int idx, vector<bool> &used)
{
    if (curSum == target)
    {
        res.push_back(path);
        return;
    }
    if (curSum > target)
    {
        return;
    }
    for (int i = idx; i < candidates.size(); i++)
    {
        if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
        {
            continue;
        }
        path.push_back(candidates[i]);
        curSum += candidates[i];
        used[i] = true;
        back(candidates, target, i + 1, used);
        path.pop_back();
        curSum -= candidates[i];
        used[i] = false;
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<bool> used(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    back(candidates, target, 0, used);
    return res;
}
int main()
{
}