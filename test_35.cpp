#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int searchInsert(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int mid = (left + right) / 2;
    ;
    int res = 0;
    while (left <= right && left < nums.size())
    {
        /* code */
        mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            /* code */
            right = mid - 1;
        }
        else
        {
            /* code */
            
            break;
        }
    }
    while (mid < nums.size() && nums[mid] < target)
    {
        /* code */
        mid++;
        
    }
    
    return mid;
}
int main()
{
    vector<int> xx = {1, 3,5,6};
    cout << searchInsert(xx, 7);
}