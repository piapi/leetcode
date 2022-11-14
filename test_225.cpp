#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

class MyStack
{
public:
    queue<int> qin;
    queue<int> qout;
    MyStack()
    {
    }

    void push(int x)
    {
        qin.push(x);
    }

    int pop()
    {
        if (qout.empty())
        {
            while (!qin.empty())
            {
                qout.push(qin.front());
                qin.pop();
            }
        }
        int res = qout.front();
        qout.pop();
        return res;
    }

    int top()
    {
        if (qout.empty())
        {
            while (!qin.empty())
            {
                qout.push(qin.front());
                qin.pop();
            }
        }
        int res = qout.front();
        return res;
    }

    bool empty()
    {
        return qin.empty() && qout.empty();
    }
};
int main()
{
}