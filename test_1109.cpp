#include <vector>
using namespace std;
#include<iostream>
//使用差分数组
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> di(n, 0);
    vector<int> res(n, 0);
    for (int i = 0; i < bookings.size(); i++)
    {
        di[bookings[i][0] - 1] += bookings[i][2];
        if (bookings[i][1] < n)
        {
            di[bookings[i][1]] -= bookings[i][2];
        }
    }
    res[0] = di[0];
    for (int i = 1; i < n; i++)
    {
        res[i] = res[i - 1] + di[i];
    }
    return res;
}
int main(){
    vector<vector<int>> bookings={{1,2,10},{2,3,20},{2,5,25}};
    vector<int>res=corpFlightBookings(bookings,5);
    for (size_t i = 0; i < 5; i++)
    {
        /* code */
        cout<<res[i]<<"\t";
    }
    

}