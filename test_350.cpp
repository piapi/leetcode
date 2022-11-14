#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = 0;
    int n2 = 0;
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    while (n1 < nums1.size() && n2 < nums2.size())
    {
        if (nums1[n1] < nums2[n2])
        {
            n1++;
        }
        else if (nums1[n1] > nums2[n2])
        {
            n2++;
        }
        else
        {
            res.push_back(nums1[n1]);
            n1++;
            n2++;
        }
    }
    return res;
}
int main()
{
    vector<int> n1 = {1, 2, 2, 1, 4, 9, 5};
    vector<int> n2 = {2, 2, 9, 4, 9, 8, 4};
    vector<int> res = intersect(n1, n2);
    for (size_t i = 0; i < res.size(); i++)
    {
        /* code */
        cout << res[i] << "\t";
    }
    cout << endl;
}