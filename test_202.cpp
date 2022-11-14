#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
int pf(int n)
{
    int temp = n;
    int sum = 0;
    while (temp > 0)
    {
        /* code */
        sum += (temp % 10) * (temp % 10);
        temp = temp / 10;
    }
    return sum;
}
bool isHappy(int n)
{

    int slow = n;
    int fast = pf(n);
    if (pf(slow) == 1 || pf(fast) == 1)
    {
        /* code */
        return true;
    }
    while (fast != slow)
    {
        /* code */
        if (pf(slow) == 1 || pf(fast) == 1)
        {
            /* code */
            return true;
        }
        slow = pf(slow);
        fast = pf(pf(fast));
    }
    return false;
}
int main()
{
    cout << isHappy(19);
}