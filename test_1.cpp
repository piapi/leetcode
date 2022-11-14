#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    unordered_map<int,int>um;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!um.count(target-nums[i]))
        {
            um[nums[i]]=i;
            cout<<nums[i]<<"\t"<<i<<endl;
        }else{
            cout<<target-nums[i]<<endl;
            res.push_back(um[target-nums[i]]);
            res.push_back(i);
            break;
        }
        
    }
    return res;
    
}
int main()
{
    vector<int> n1 = {3,2,4};

    vector<int> res = twoSum(n1, 6);
}