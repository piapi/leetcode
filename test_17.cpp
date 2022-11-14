#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
vector<string> temp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string str;
vector<string> res;
void back(string digits,int idx){
    if (str.length()==digits.length())
    {
        res.push_back(str);
        return;
    }
    for (int i = idx; i < digits.length(); i++)
    {
        for (int j = 0; j < temp[digits[i] - '2'].length(); j++)
        {
            str.push_back(temp[digits[i] - '2'][j]);
            back(digits, i + 1);
            str.pop_back();
        }  
    } 
}
vector<string> letterCombinations(string digits)
{
    if (digits.length()==0)
    {
        return res;
    }
    
    back(digits, 0);
    return res;
}
int main()
{
    vector<string> xx=letterCombinations("23");
    for (string s:xx)
    {
        cout << s << endl;
    }
    
}