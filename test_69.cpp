#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
int mySqrt(int x)
{
    int left = 0;
    int right = x;
    if (x == 1)
    {
        /* code */
        return 1;
    }

    int mid = (left + right) / 2.0;
    while (left < right - 1)
    {

        mid = (left + right) / 2.0;
        if (x / mid < mid)
        {
            /* code */
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return left;
}
int main()
{
    cout << mySqrt(1000000000);
}