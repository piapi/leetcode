#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
vector<string> path;
int curSum = 0;
vector<vector<string>> res;
bool isTrue(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void back(string s, int idx)
{
    if (idx>=s.length())
    {
        res.push_back(path);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (isTrue(s,idx,i))
        {
            path.push_back(s.substr(idx,i-idx+1));
        }else{
            continue;
        }
        back(s,i+1);
        path.pop_back();
    }
    
}
vector<vector<string>> partition(string s)
{
    back(s,0);
    return res;
}
int main()
{
}