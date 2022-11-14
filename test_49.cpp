#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    unordered_map<string,int> ump;
    for (int i = 0; i < strs.size(); i++)
    {
        string temp=strs[i];
        vector<string> temp1;
        sort(temp.begin(),temp.end());
        if (!ump.count(temp))
        {
            ump[temp]=res.size();
            temp1.push_back(strs[i]);
            res.push_back(temp1);
        }else{
            res[ump[temp]].push_back(strs[i]);
        }
        
    }   
    return res;
}
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "baat"};
    vector<vector<string>> res=groupAnagrams(strs);
}