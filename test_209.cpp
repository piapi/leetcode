#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int minSubArrayLen(int target, vector<int> &nums)
{

    int left = 0;
    int right = 0;
    int temp = nums[0];
    int res = 999999;
    while (left < nums.size())
    {
        /* code */
        if (temp < target)
        {
            if (right < nums.size() - 1)
            {
                /* code */
                temp += nums[++right];
            }
            else
            {
                if(left==0){
                    res=0;
                    break;
                }
                temp -= nums[left++];
            }
        }
        else
        {
            res = min(res, right - left + 1);
            temp -= nums[left++];
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {1,2,3,4,5};
    int z = minSubArrayLen(11, nums);
    cout << z<<"\n";
}