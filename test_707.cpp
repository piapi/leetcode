#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
class MyLinkedList
{

public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    MyLinkedList()
    {
        _dummyHead = new ListNode(0);
        _size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index > _size)
        {
            return -1;
        }
        ListNode *head = _dummyHead;
        int i = 0;
        while (i < index)
        {
            head = head->next;
            i++;
        }
        return head->val;
    }
    void addAtHead(int val)
    {
        if (_size == 0)
        {
            _dummyHead->val = val;
        }
        else
        {
            ListNode *head = new ListNode(val);
            head->next = _dummyHead;
            _dummyHead = head;
        }

        _size++;
    }

    void addAtTail(int val)
    {
        ListNode *head = _dummyHead;
        while (head->next != nullptr)
        {
            head = head->next;
        }
        head->next = new ListNode(val);
        _size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index <= 0)
        {
            addAtHead(val);
        }
        else if (index > _size)
        {
            return;
        }
        else if (index == _size)
        {
            addAtTail(val);
        }
        else
        {
            ListNode *head = new ListNode(val);
            head->next = _dummyHead;
            ListNode *temp=head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->next = new ListNode(val,temp->next);
            _dummyHead=head->next;
        }
        _size++;
    }

    void deleteAtIndex(int index)
    {
        ListNode *head = new ListNode(0);
        head->next = _dummyHead;
        ListNode *temp = head;
        if (index < 0 || index > _size)
        {
            return;
        }

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        _dummyHead = head->next;
        _size--;
    }
    void show()
    {
        ListNode *head = _dummyHead;
        cout << "size:" << _size << endl;
        while (head != nullptr)
        {
            std::cout << head->val << "\t";
            head = head->next;
        }
        std::cout << "\n";
    }

private:
    int _size;
    ListNode *_dummyHead;
};
int main()
{
    MyLinkedList *mn = new MyLinkedList();
    mn->addAtHead(1);
    mn->show();
    mn->addAtTail(3);
    mn->show();
    mn->addAtIndex(1, 2);
    mn->show();
    cout << mn->get(1) << endl;
    mn->deleteAtIndex(1);
    mn->show();
    
}