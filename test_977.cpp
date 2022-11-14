#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
vector<int> sortedSquares(vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        /* code */
        nums[i]=nums[i]*nums[i];
    }
    sort(nums.begin(),nums.end());
    return nums;
}
int main()
{
}