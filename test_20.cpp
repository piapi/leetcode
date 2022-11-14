#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
bool isValid(string s)
{
    stack<char> temp;
    for (int i = 0; i < s.length(); i++)
    {

        if (temp.empty())
        {
            temp.push(s[i]);
        }
        else
        {

            if (temp.top() == '(' && s[i] == ')' || temp.top() == '[' && s[i] == ']' || temp.top() == '{' && s[i] == '}')
            {
                temp.pop();
            }else{
                 temp.push(s[i]);
            }
        }
    }
    return temp.empty();
}
int main()
{
    cout << isValid("({[)") << endl;
}