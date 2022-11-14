#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    vector<int> scnt(26, 0);
    vector<int> pcnt(26, 0);
    sort(p.begin(), p.end());
    int plen = p.length();
    int slen = s.length();
    if (slen < plen)
    {
        return res;
    }
    for (int i = 0; i < plen; i++)
    {
        scnt[s[i] - 'a']++;
        pcnt[p[i] - 'a']++;
    }

    if (scnt == pcnt)
    {
        res.push_back(0);
    }
    for (int i = 0; i < slen - plen; ++i)
    {
        --scnt[s[i] - 'a'];
        ++scnt[s[i + plen] - 'a'];

        if (scnt == pcnt)
        {
            res.push_back(i + 1);
        }
    }

    return res;
}
int main()
{
    vector<int> res = findAnagrams("aa", "bb");

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\t";
    }
}