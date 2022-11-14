#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
vector<int> path;
vector<vector<int>> res;
bool isEqual(vector<int> temp, int target)
{
    for (int t : temp)
    {
        target -= t;
    }
    if (target == 0)
    {
        return true;
    }
    return false;
}
void back(int k,int n,int idx){
    if (path.size()==k)
    {
        if (isEqual(path,n))
        {
            res.push_back(path);
        }
        return;
    }
    for (int i = idx; i < 9; i++)
    {
        path.push_back(i);
        back(k,n,i+1);
        path.pop_back();
    }
    
}
vector<vector<int>> combinationSum3(int k, int n)
{
    back(k,n,1);
    return res;
}
int main()
{
    combinationSum3(4, 2);
    for (int i = 0; i < res.size(); i++)
    {
        for (int x : res[i])
        {
            cout << x << "\t";
        }
        cout << endl;
    }
}