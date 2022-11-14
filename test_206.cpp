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

ListNode *reverseList(ListNode *head)
{
    ListNode *res=nullptr;
    while (head!=nullptr)
    {
        ListNode *temp=new ListNode(head->val);
        temp->next=res;
        res=temp;
        head=head->next;
        
    }
    return res;
    
}
int main()
{
}