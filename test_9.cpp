#include <vector>
using namespace std;
#include <iostream>
//双指针左右指针
bool isPalindrome(int x)
{
    string str = to_string(x);
    int left=0;
    int right=str.length()-1;
    while (left<=right)
    {
        /* code */
        if (str[left++]!=str[right--])
        {
            /* code */
            return false;
        }
        
    }
    return true;
}
int main()
{
    cout<<isPalindrome(-121);
}