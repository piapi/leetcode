#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
string reverseStr(string s, int k)
{
    int k2 = 2 * k;
    if (s.length() < k)
    {
        reverse(s.begin(), s.end());
        return s;
    }
    else if (s.length() < 2 * k)
    {
        reverse(s.begin(), s.begin() + k);
        return s;
    }

    int i = k2;
    for (; i <= s.length(); i += k2)
    {
        reverse(s.begin() + i - k2, s.begin() + i - k);
        // cout << s << endl;
    }
    i = i - k2;
    int t = s.size() - i;
    if (0 < t && t < k)
    {
        reverse(s.begin() + i, s.end());
    }
    else if (0 < t && t < 2 * k)
    {
        reverse(s.begin() + i, s.begin() + i + k);
    }

    return s;
}
int main()
{
    string str = "abcd";
    cout << reverseStr(str, 2) << endl;
}