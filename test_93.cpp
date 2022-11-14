#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
vector<string> path;
int curSum = 0;
vector<string> res;

void back(string s, int idx)
{
    if (idx >= s.length())
    {
        if (path.size()==4)
        {
            string temp="";
            for (int i = 0; i < 4; i++)
            {
                temp+=path[i];
                temp+=".";
            }
            temp.pop_back();
            res.push_back(temp);
        }
        
        return;
    }
    for(int i=idx;i<s.length();i++){
        string ss=s.substr(idx,i-idx+1);
        if (atoi(ss.c_str())>=0 && atoi(ss.c_str())<=255 && (ss.length()>1 && ss[0]!='0' || ss.length()==1))
        {
            cout<<ss<<endl;
            path.push_back(ss);
        }else{
            continue;
        }
        back(s,i+1);
        path.pop_back();
    }
    
}
vector<string> restoreIpAddresses(string s)
{
    back(s,0);
    return res;
}
int main()
{
    vector<string> xx=restoreIpAddresses("25525511135");
}