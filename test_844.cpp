#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
bool backspaceCompare(string s, string t)
{
    int slen = s.length();
    int tlen = t.length();
    int curs = 0;
    int curt = 0;
    for (int i = 0; i < slen; i++)
    {
        s[curs] = s[i];
        if (s[i] != '#')
        {
            curs++;
        }
        else
        {
            if (curs > 0)
            {
                curs--;
            }
        }
    }
    for (int i = 0; i < tlen; i++)
    {
        t[curt] = t[i];
        if (t[i] != '#')
        {
            curt++;
        }
        else
        {
            if (curt > 0)
            {
                curt--;
            }
        }
    }
    if (curt!=curs)
    {
        return false;
    }
    if(curs==curs && curs==0){return true;}
    for (size_t i = 0; i < curt; i++)
    {
        /* code */
        if (s[i]!=t[i])
        {
            /* code */
            return false;
        }
        
    }
    
    return true;
}
int main()
{
    cout << backspaceCompare("a##c", "#a#c");
}