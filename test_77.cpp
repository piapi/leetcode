#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
vector<int> path;
vector<vector<int>> res;
bool isEqual(vector<int>temp,int target){
    for(int t : temp){
        target-=t;
    }
    if (target==0)
    {
        return true;
    }
    return false;
}

vector<vector<int>> combine(int n, int k)
{
    
}
int main()
{
    combine(4, 2);
    for (int i = 0; i < res.size(); i++)
    {
        for (int x : res[i])
        {
            cout << x << "\t";
        }
        cout << endl;
    }
}