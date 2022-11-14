#include <vector>
using namespace std;
#include <iostream>

int removeDuplicates(vector<int> &nums)
{
    int i=0,j=1;
    while (i<nums.size() && j<nums.size())
    {
        /* code */
        if (nums[i]!=nums[j])
        {
            /* code */
            nums[++i]=nums[j++];
        }else{
            j++;
        }
        
    }
    return i+1;
    
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int x=removeDuplicates(nums);
    cout<<x<<"\n";
    for (size_t i = 0; i < nums.size(); i++)
    {
        /* code */
        cout<<nums[i]<<"\t";
    }
    
}