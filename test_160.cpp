#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int a = 0;
    int b = 0;
    ListNode *tA = headA;
    ListNode *tB = headB;
    while (tA != nullptr)
    {
        a++;
        tA = tA->next;
    }
    while (tB != nullptr)
    {
        b++;
        tB = tB->next;
    }
    tA = headA;
    tB = headB;
    if (a > b)
    {
        int i = 0;
        while (i < a - b)
        {
            tA = tA->next;
            i++;
        }
        while (tA != nullptr && tB != nullptr)
        {
            if (tA == tB)
            {
                return tA;
            }
            tA = tA->next;
            tB = tB->next;
        }
    }
    else
    {
        int i = 0;
        while (i < b - a)
        {
            tB = tB->next;
            i++;
        }
        while (tA != nullptr && tB != nullptr)
        {

            if (tA == tB)
            {
                return tA;
            }
            tA = tA->next;
            tB = tB->next;
        }
    }
    return nullptr;
}

int main()
{
}