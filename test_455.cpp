#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int findContentChildren(vector<int> &g, vector<int> &s)
{
    int res=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int indg=0;
    int inds=0;
    while (indg<g.size() && inds<s.size())
    {
        if (s[inds]>=g[indg])
        {
            indg++;
            inds++;
            res++;
        }else{
            inds++;
        }   
    }
    return res;
}
int main()
{
}