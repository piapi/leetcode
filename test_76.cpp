#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>

bool panduan(vector<int> zimu,
             vector<int> cishu)
{
    for (int i = 0; i < 128; i++)
    {
        if (zimu[i] > cishu[i])
        {
            /* code */
            return false;
        }
    }
    return true;
}
string minWindow(string s, string t)
{
    int left = 0;
    int right = 0;
    vector<int> zimu(128, 0);  //需要的次数
    vector<int> cishu(128, 0); //已经出现的次数
    string res = "";
    int len = 99999;
    if (s.length() < t.length())
    {
        return res;
    }

    for (int i = 0; i < t.size(); i++)
    {
        /* code */
        zimu[t[i]] += 1;
    }
    while (right < s.length() && left <= right)
    {
        if (zimu[s[right]])
        {
            cishu[s[right]] += 1;
        }

        while (panduan(zimu, cishu))
        {
            /* code */
            if (len > right - left + 1)
            {
                /* code */
                len = right - left + 1;
                res = s.substr(left, len);
            }
            if (cishu[s[left]])
            {
                cishu[s[left]]--;
            }
            left++;
        }

        if (!panduan(zimu, cishu))
        {
            right++;
        }
    }
    return res;
}
int main()
{
    string res = minWindow("a", "aa");
    cout << res << endl;
}