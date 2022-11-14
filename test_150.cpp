#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
int evalRPN(vector<string> &tokens)
{
    int res = 0;
    stack<long long> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
            long long n1 = st.top();
            st.pop();
            long long n2 = st.top();
            st.pop();
            st.push(n2 + n1);
        }
        else if (tokens[i] == "-")
        {
            long long n1 = st.top();
            st.pop();
            long long n2 = st.top();
            st.pop();
            st.push(n2 - n1);
        }
        else if (tokens[i] == "*")
        {
            long long n1 = st.top();
            st.pop();
            long long n2 = st.top();
            st.pop();
            st.push(n2 * n1);
        }
        else if (tokens[i] == "/")
        {
            long long n1 = st.top();
            st.pop();
            long long n2 = st.top();
            st.pop();
            st.push(n2 / n1);
        }
        else
        {
            st.push(stoll(tokens[i]));
        }
    }
    res=st.top();
    return res;
}
int main()
{
}