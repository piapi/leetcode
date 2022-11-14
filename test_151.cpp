#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
string reverseWords(string s)
{
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }

        int right = i;
        while (right < s.length() && s[right] != ' ')
        {
            right++;
        }
        
        if (res.length()>0)
        {
            res = s.substr(i, right - i) + " " + res;
        }else{
            res = s.substr(i, right - i);
        }
        
       
        i = right - 1;
    }
    return res;
}
int main()
{
    cout << reverseWords("the sky is blue") << endl;
}