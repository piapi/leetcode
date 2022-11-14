#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *front = head, *back = head;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        back = back->next;
    }
    if (back==nullptr)
    {
        /* code */
        return front->next;
    }
    
    while (true)
    {
        /* code */
        back = back->next;
        if (back == nullptr)
        {
            /* code */
            front->next = front->next->next;
            break;
        }
        front = front->next;
    }
    return head;
}
int main()
{
}