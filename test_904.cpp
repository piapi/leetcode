#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int totalFruit(vector<int> &fruits)
{
    vector<pair<int, int>> lanzi;
    lanzi.emplace_back(-1, 0);
    lanzi.emplace_back(-1, 0);
    int left = 0;
    int right = 0;
    int res = 0;
    int cnt = 0;
    while (right < fruits.size())
    {

        if (lanzi[0].first != fruits[right] && lanzi[1].first != fruits[right])
        {

            if (cnt > 1)
            {
                if (lanzi[1].first == fruits[right - 1])
                {
                    left = lanzi[0].second + 1;
                    lanzi[0].first = fruits[right];
                    lanzi[0].second = right;
                }
                else if (lanzi[0].first == fruits[right - 1])
                {

                    left = lanzi[1].second + 1;
                    lanzi[1].first = fruits[right];
                    lanzi[1].second = right;
                }
            }
            else
            {
                lanzi[cnt % 2].first = fruits[right];
                lanzi[cnt % 2].second = right;
                cnt++;
            }
        }
        else if (lanzi[0].first == fruits[right])
        {
            lanzi[0].second = right;
        }
        else if (lanzi[1].first == fruits[right])
        {
            lanzi[1].second = right;
        }

        res = max(res, right - left + 1);
        right++;
    }
    return res;
}
int main()
{
    vector<int> xx = {1};
    cout << totalFruit(xx);
}