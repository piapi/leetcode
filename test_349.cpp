#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> um;
    vector<int> res;
    for (int i = 0; i < nums2.size(); i++)
    {
        if (!um.count(nums2[i]))
        {
            um[nums2[i]] = 1;
        }
    }
    cout<<um.size()<<endl;
    for (int i = 0; i < nums1.size(); i++)
    {
        if (um.count(nums1[i]) && um[nums1[i]] > 0)
        {

            um[nums1[i]]=0;
            res.push_back(nums1[i]);
        }
    }
    return res;
}
int main()
{
    vector<int> n1 = {1, 2, 2, 1,4,9,5};
    vector<int> n2 = {2, 2,9,4,9,8,4};
    vector<int> res = intersection(n1, n2);
    for (size_t i = 0; i < res.size(); i++)
    {
        /* code */
        cout<<res[i]<<"\t";
    }
    cout<<endl;
}