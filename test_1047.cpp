#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
string removeDuplicates(string s)
{

    string res = "";
    for (char ss : s)
    {
        int len = res.length();
        if (!res.length() || res[len - 1] != ss)
        {
            res += ss;
        }
        else
        {
            res.pop_back();
        }
    }

    return res;
}
int main()
{
    cout<<removeDuplicates("abbaca");
}