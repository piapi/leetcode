#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
string replaceSpace(string s)
{
    string res="";
    for(char ss : s){
        if (ss==' ')
        {
           res+="%20";
        }else{
            res+=ss;
        }
    }
    return res;
}
int main()
{
    cout<<replaceSpace("We are happy");
}