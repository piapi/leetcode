#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> ump1;
    int res = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (!ump1.count(nums1[i] + nums2[j]))
            {
                ump1[nums1[i] + nums2[j]] = 1;
            }
            else
            {
                ump1[nums1[i] + nums2[j]] += 1;
            }
        }
    }
    for (int i = 0; i < nums3.size(); i++)
    {
        for (int j = 0; j < nums4.size(); j++)
        {
            res += ump1[-(nums3[i] + nums4[j])];
        }
    }
    return res;
}
int main()
{
    vector<int> n1 = {-1, -1};
    vector<int> n2 = {-1, 1};
    vector<int> n3 = {-1, 1};
    vector<int> n4 = {1, -1};
    int res = fourSumCount(n1, n2, n3, n4);
}