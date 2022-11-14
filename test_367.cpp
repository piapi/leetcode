#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
bool isPerfectSquare(int num)
{
    long int left=0;
    long int right=num;
    if (num==1)
    {
        /* code */
        return true;
    }
    
    while (left<right-1)
    {
        /* code */
        long int mid=(left+right)/2;
        if (num==(mid*mid))
        {
            /* code */
            return true;
        }else if (num>(mid*mid))
        {
            /* code */
            left=mid;
        }else{
            right=mid;
        }
        
        
    }
    return false;
}
int main()
{
    cout<<isPerfectSquare(2000105819);
}