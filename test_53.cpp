#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int maxSubArray(vector<int> &nums)
{
    int res=nums[0];
    int maxR=nums[0];
    for (size_t i = 1; i < nums.size(); i++)
    {
        if(res<0){
            int temp=max(res,nums[i]);
            maxR=max(temp,maxR);
            res=nums[i];     
        }else{
            int temp=max(res,res+nums[i]);
            maxR=max(temp,maxR);
            res+=nums[i];
        }
    }
    return maxR;  
}
int main()
{
    vector<int> nums={-1,-1,-2,-2};
    cout<<maxSubArray(nums);
}