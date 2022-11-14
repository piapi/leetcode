#include <vector>
using namespace std;
#include <iostream>
string addStrings(string num1, string num2)
{
    int len1 = num1.length() - 1;
    int len2 = num2.length() - 1;
    string ans = len1 < len2 ? num2 : num1;
    int len_ans = ans.length() - 1;
    int v1 = 0;
    int v2 = 0;
    int carry = 0;
    while (len1 >= 0 || len2 >= 0)
    {
        /* code */
        if (len1 < 0)
        {
            /* code */
            v2 = num2[len2--] - '0';
            v1 = 0;
        }
        else if (len2 < 0)
        {
            v1 = num1[len1--] - '0';
            v2 = 0;
        }
        else
        {
            v2 = num2[len2--] - '0';
            v1 = num1[len1--] - '0';
        }
        ans[len_ans--] = (v1 + v2 + carry) % 10 + '0';
        carry = (v1 + v2 + carry) / 10;
    }
    if (carry > 0)
    {
        /* code */
        ans.insert(0, 1, carry + '0');
    }
    return ans;
}
int main()
{
    string num1 = "11";
    string num2 = "123";
    cout << addStrings(num1, num2);
}