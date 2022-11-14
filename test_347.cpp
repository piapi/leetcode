#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
vector<int> topKFrequent(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    vector<int> res;
    priority_queue<pair<int, int>> pq;
    if (nums.size() == 1)
    {
        /* code */
        pq.push({1, nums[0]});
    }

    int cnt = 1;
    int i = 1;
    while (i < nums.size())
    {
        /* code */
        if (nums[i] != nums[i - 1])
        {
            /* code */
            pq.push({cnt, nums[i - 1]});
            cnt = 1;
            i++;
        }
        while (nums[i] == nums[i - 1] && i<nums.size())
        {
            /* code */
            cnt++;
            i++;
        }
        if (i == nums.size())
        {
            /* code */
            pq.push({cnt, nums[i - 1]});
            break;
        }
    }

    for (i = 0; i < k && !pq.empty(); i++)
    {
        /* code */
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
int main()
{
    vector<int> arr = {-1, -1,1,2,3,6,2,3,1,2};
    vector<int> res = topKFrequent(arr, 3);
    for (size_t i = 0; i < res.size(); i++)
    {
        /* code */
        cout << res[i] << "\t";
    }
    cout << "\n";
}