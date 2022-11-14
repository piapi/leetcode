#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>

int removeElement(vector<int> &nums, int val)
{
    int left=0;
    int right=0;
    int res=nums.size();
    while (right<nums.size())
    {
        while (nums[right]==val)
        {
            /* code */
            res--;
            right++;
            if (right==nums.size())
            {
                /* code */
                return res;
            }
            
        }
        
        
        nums[left++]=nums[right++];
        
        
        
    }
    return res;
    
}
int main()
{
    vector<int> xx={3,2,2,3};
    int re=removeElement(xx,3);
    for (size_t i = 0; i < re; i++)
    {
        /* code */
        cout<<xx[i]<<"\t";
    }
    
}