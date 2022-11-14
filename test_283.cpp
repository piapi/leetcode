#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
void moveZeroes(vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int res = nums.size();
    while (right < nums.size())
    {
        while (nums[right] == 0)
        {
            /* code */
            res--;
            right++;
            if (right == nums.size())
            {
                break;
            }
        }
        nums[left++] = nums[right++];
    }
    for (int i = res; i < nums.size(); i++)
    {
        /* code */
        nums[i]=0;
    }
    
}
int main()
{
    vector<int> ar={0};
    moveZeroes(ar);
    for (size_t i = 0; i < ar.size(); i++)
    {
        /* code */
        cout<<ar[i]<<"\t";
    }
    cout<<endl;
}