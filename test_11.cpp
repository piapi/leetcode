#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int h = height[left] < height[right] ? height[left] : height[right];
    int res = (right - left) * h;
    while (left < right)
    {
        /* code */
        h = height[left] < height[right] ? height[left] : height[right];
        int temp = (right - left) * h;
        if (temp > res)
        {
            /* code */
            res = temp;
        }
        if (height[left] < height[right])
        {
            /* code */
            left++;
        }
        else
        {
            right--;
        }
    }
    return res;
}
int main()
{
    vector<int> x={1,8,6,2,5,4,8,3,7};
    int res=maxArea(x);
}