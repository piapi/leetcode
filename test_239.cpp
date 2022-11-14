#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    priority_queue<std::pair<int, int>> pri_que;
    vector<int> res;
    for (size_t i = 0; i < nums.size(); i++)
    {
        /* code */
        if (i < k)
        {
            /* code */
            pair<int, int> temp;
            temp.first = nums[i];
            temp.second = i;
            pri_que.push(temp);
        }
        else
        {
            /* code */
            res.push_back(pri_que.top().first);
            while (!pri_que.empty() && i - pri_que.top().second >= k)
            {
                /* code */
                pri_que.pop();
            }
            pair<int, int> temp;
            temp.first = nums[i];
            temp.second = i;
            pri_que.push(temp);
        }
    }
    res.push_back(pri_que.top().first);
    return res;
}
int main()
{
    vector<int> arr = {1,-1};
    vector<int> res = maxSlidingWindow(arr, 1);
    for (size_t i = 0; i < res.size(); i++)
    {
        /* code */
        cout << res[i] << "\t";
    }
    cout << "\n";
}