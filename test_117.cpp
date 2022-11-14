#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    queue<Node *> qn;
    if (root != nullptr)
    {
        qn.push(root);
    }
    while (!qn.empty())
    {
        int size = qn.size();
        for (int i = 0; i < size; i++)
        {
            Node *cur = qn.front();
            qn.pop();
            if (i == size - 1)
            {
                cur->next = nullptr;
            }
            else
            {
                cur->next = qn.front();
            }
            if (cur->left)
            {
                qn.push(cur->left);
            }
            if (cur->right)
            {
                qn.push(cur->right);
            }
        }
    }
    return root;
}