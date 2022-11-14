#include <vector>
using namespace std;
#include <iostream>
//使用逆序对，归并排序思想
int count = 0;

void merge(vector<int> &nums, int left, int right)
{
    
    int mid = (left + right) / 2;
    int s1 = left;
    int s2 = mid + 1;
    int *temp = new int[right - left + 1];
    int i = 0;
    while (s1 <= mid && s2 <= right)
    {
        /* code */
        if (nums[s1] <= nums[s2])
        {
            /* code */
            temp[i++] = nums[s1++];
        }
        else
        {
            /* code */
            count += mid - s1 + 1;
            temp[i++] = nums[s2++];
        }
    }
    while (s1 <= mid)
    {
        /* code */
        temp[i++] = nums[s1++];
    }
    while (s2 <= right)
    {
        /* code */
        temp[i++] = nums[s2++];
    }
    for (int j = 0; j <= right - left; j++)
    {
        /* code */
        nums[j + left] = temp[j];
    }
}
void mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        /* code */
        return;
    }
    int mid = (right + left) / 2;
    mergeSort(nums,left,mid);
    mergeSort(nums,mid+1,right);
    merge(nums,left,right);

}
int reversePairs(vector<int> &nums)
{
    mergeSort(nums,0,nums.size()-1);
    return count;
}
int main()
{
    vector<int> nums = {7, 5, 6, 4};
    int res = reversePairs(nums);
    cout << res;
}