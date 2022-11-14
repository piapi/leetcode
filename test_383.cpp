#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
bool canConstruct(string ransomNote, string magazine)
{
    vector<int> ts(128, 0);
    vector<int> tt(128, 0);
    for (size_t i = 0; i < ransomNote.length(); i++)
    {
        ts[ransomNote[i]] += 1;
    }
    for (size_t i = 0; i < magazine.length(); i++)
    {
        /* code */
        tt[magazine[i]] += 1;
    }
    for (size_t i = 0; i < 128; i++)
    {
        if (ts[i] > tt[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
}