#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
bool isAnagram(string s, string t)
{
    vector<int> ts(128,0);
    vector<int> tt(128,0);
    for (size_t i = 0; i < s.length(); i++)
    {
        ts[s[i]]+=1;
    }
    for (size_t i = 0; i < t.length(); i++)
    {
        /* code */
        tt[t[i]]+=1;
    }
    for (size_t i = 0; i < 128; i++)
    {
        if (ts[i]!=tt[i])
        {
            return false;
        }
        
    }
    return true;
    
}
int main()
{
    
}