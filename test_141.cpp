#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        /* code */
        return false;
    }

    ListNode *fast = head->next;
    ListNode *slow = head;
    while (fast != slow)
    {
        /* code */
        if (fast == nullptr || fast->next == nullptr)
        {
            /* code */
            return false;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;
}
int main()
{
}