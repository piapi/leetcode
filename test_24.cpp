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

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *res = new ListNode(0);
    res->next=head;
    ListNode *cur = res;
    cout<<"start"<<endl;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        ListNode *left = cur->next;
        ListNode *right = cur->next->next->next;
        cur->next = cur->next->next;       
        cur->next->next = left;
        cur->next->next->next = right;
        cur = cur->next->next;
    }
    return res->next;
}

int main()
{
    ListNode *res = new ListNode(0);
    ListNode *temp=res;
    for (size_t i = 1; i < 5; i++)
    {
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    res=res->next;
    //     while (res!=nullptr)
    // {
    //     cout<<res->val<<"\t";
    //     res=res->next;
    // }
    cout<<endl;
    ListNode *xx=swapPairs(res);

    
    
}