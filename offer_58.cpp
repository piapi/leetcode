#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
string reverseLeftWords(string s, int n)
{
    n=n%s.length();
    string temp=s.substr(0,n);
    int len=s.length();
    for (int i = 0; i < len-n; i++)
    {
        s[i]=s[i+n];
    }
    for (int i = len-n; i < len; i++)
    {
        s[i]=temp[i-len+n];
    }
    return s;
    
}
int main()
{
    cout<<reverseLeftWords("lrloseumgh",6);
}