#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>

int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    int res = -1;
    while (left <= right)
    {
        /* code */
        int mid = (left + right) / 2;
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
            res = mid;
            break;
        }
    }
    return res;
}
int main()
{
    vector<int> xx = {-1, 0, 3, 5, 9, 12};
    cout << search(xx, 2);
}