#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *res = new ListNode(0);
    res->next = head;
    ListNode *temp = res;
    while (temp->next != nullptr)
    {
        if (temp->next->val == val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return res->next;
}

int main()
{
    ListNode *res = new ListNode(0);
    ListNode *xx = res;
    for (int i = 1; i < 7; i++)
    {
        ListNode *temp = new ListNode(i);
        xx->next = temp;
        xx = xx->next;
    }
    res = res->next;
    ListNode *iu = removeElements(res, 6);
}