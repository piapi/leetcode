#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
struct cmp1
{
    bool operator()(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b)
    {
        return a.first > b.first;
    }
};
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{

    vector<vector<int>> res;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, cmp1> q; //从小到大
    for (int i = 0; i < nums1.size() && i < k; i++)
    {
        /* code */
        q.push({nums1[i]+nums2[0],{i,0}});
    }
    while (!q.empty() && k)
    {
        /* code */
        int temp=q.top().first;
        int x=q.top().second.first;
        int y=q.top().second.second;
        q.pop();
        res.push_back({nums1[x],nums2[y]});
        if(nums2.size()-1>y){
            q.push({nums1[x]+nums2[y+1],{x,y+1}});
        }
        k--;
    }
    
    return res;
}

int main()
{
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3};
    vector<vector<int>> res = kSmallestPairs(arr1, arr2, 2);
    for (size_t i = 0; i < res.size(); i++)
    {
        /* code */
        cout<<res[i][0]<<"\t"<<res[i][1]<<"\n";
    }
    
}


