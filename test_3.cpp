#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
int lengthOfLongestSubstring(string s)
{
    unordered_map<int, int> dictionary;
    int slow = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        /* code */

        /* code */
        slow = max(dictionary[s[i]], slow);
        dictionary[s[i]] = i + 1;
        res = max(res, i - slow + 1);
    }
    return res;
}
int main()
{
    string s = "abcabcbb";
    int res = lengthOfLongestSubstring(s);
}