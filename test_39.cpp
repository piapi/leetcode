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
void back(vector<int> &candidates, int target, int idx)
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
        path.push_back(candidates[i]);
        curSum += candidates[i];
        back(candidates, target, i);
        path.pop_back();
        curSum -= candidates[i];
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    back(candidates, target, 0);
    return res;
}
int main()
{
