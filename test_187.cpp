#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <unordered_map>
vector<string> findRepeatedDnaSequences(string s)
{

    vector<string> res;
    unordered_map<string, int> temp;
    int len=s.length() - 10;
    for (int i = 0; i <= len; i++)
    {
        /* code */
        string xx = s.substr(i, 10);
        if (temp.empty())
        {
            /* code */
            temp[xx] = 1;
        }
        else
        {
            if (temp.count(xx))
            {
                /* code */
                if (temp[xx] == 1)
                {
                    res.push_back(xx);
                }
            
                temp[xx] += 1;
                
            }
            else
            {
                /* code */
                temp[xx] = 1;
            }
        }
    }
    return res;
}
int main()
{
    string s = "AAAAAAAAAAA";
    vector<string> res=findRepeatedDnaSequences(s);
    for (string ss: res)
    {
        /* code */
        cout<<ss<<"\t";
    }
    
}