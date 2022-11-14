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
void back(vector<int> &nums,int idx){
    res.push_back(path);
    for (int i = idx; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        back(nums,i+1);
        path.pop_back();
    }
    
}
vector<vector<int>> subsets(vector<int> &nums)
{
    back(nums,0);
    return res;
}
int main()
{
}