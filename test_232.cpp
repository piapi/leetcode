#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
class MyQueue
{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue()
    {
    }

    void push(int x)
    {
        stIn.push(x);
    }

    int pop()
    {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty())
        {
            // 从stIn导入数据直到stIn为空
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek()
    {
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res);       // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    bool empty()
    {
        return stIn.empty() && stOut.empty();
    }
};
int main()
{
}