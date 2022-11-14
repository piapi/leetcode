#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>

bool static cmp(const vector<string> &a, const vector<string> &b)
{
    return a[1] < b[1];
}

vector<string> path;
vector<string> res;
bool find;

void back(vector<vector<string>> &tickets, vector<bool> &used, string &from, bool &find)
{
    if (find)
    {
        return;
    }   
    if (path.size() == tickets.size() + 1)
    {
        res = path;
        find = true;
        return;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] != from || used[i])
        {
            continue;
        }
        used[i] = true;
        from=tickets[i][1];
        path.push_back(from);
        back(tickets, used, from, find);
        used[i] = false;
        from=tickets[i][0];
        path.pop_back();
    }
}
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    sort(tickets.begin(), tickets.end(), cmp);
    vector<bool> used(tickets.size(), false);
    string from = "JFK";
    bool find=false;
    path.push_back("JFK");
    back(tickets, used, from, find);
    return res;
}
int main()
{
    vector<vector<string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> xx = findItinerary(tickets);
}