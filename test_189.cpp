#include <vector>
using namespace std;
#include <iostream>
void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        int j=(i + k) % nums.size();
        res[j] = nums[i];
    }
    nums.swap(res);
}
int main()
{
    vector<int> nums = {-1,-100,3,99};
    rotate(nums, 2);
    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        cout<<nums[i];
    }
}