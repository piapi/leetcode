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

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    if (fast == nullptr || fast->next == nullptr || fast->next->next == nullptr)
    {
        /* code */
        return nullptr;
    }
    slow = slow->next;
    fast = fast->next->next;

    while (slow != fast)
    {
        /* code */
        if (fast == nullptr || fast->next == nullptr)
        {
            /* code */
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while (fast != slow)
    {
        /* code */
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
int main()
{
}