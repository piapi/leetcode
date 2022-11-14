#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int lastStoneWeight(vector<int> &stones)
{
    if (stones.size() == 1)
    {
        /* code */
        return stones[0];
    }

    priority_queue<int> pq;
    for (size_t i = 0; i < stones.size(); i++)
    {
        /* code */
        pq.push(stones[i]);
    }

    while (pq.size() > 1)
    {
        /* code */
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();
        if (temp2==temp1)
        {
            /* code */
            if (pq.empty())
            {
                /* code */
                pq.push(0);
            }
            
            continue;
        }else{
            pq.push(temp1-temp2);
        }
        
    }
    return pq.top();
}
int main()
{
    vector<int> x={31,26,33,21,40};
    cout<<lastStoneWeight(x);

}