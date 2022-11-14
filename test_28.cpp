#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
int strStr(string haystack, string needle)
{
    int res = -1;

    int nlen = needle.length();
    int dl = haystack.length() - nlen;
    for (int i = 0; i <= dl; i++)
    {
        string temp = haystack.substr(i, nlen);
        if (temp == needle)
        {
            res = i;
            break;
        }
    }
    return res;
}
int main()
{
    cout << strStr("aaa", "aaaa");
}