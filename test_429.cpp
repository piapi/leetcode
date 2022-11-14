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
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> res;
    queue<vector<Node *>> trq;
    vector<Node *> chd;
    if (root != nullptr)
    {
        chd.push_back(root);
        trq.push(chd);
    }
    while (!trq.empty())
    {
        vector<int> temp;
        int size = trq.size();
        for (int i = 0; i < size; i++)
        {
            vector<Node *> cur = trq.front();
            trq.pop();
            for (Node *n : cur)
            {
                temp.push_back(n->val);
                if (!n->children.empty())
                {
                    trq.push(n->children);
                }
            }
        }
        res.push_back(temp);
    }
    return res;
}
int main()
{
}