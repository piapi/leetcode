#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
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

int maxDepth(Node *root)
{
    queue<Node*> qn;
    int res=0;
    if (root!=nullptr)
    {
        qn.push(root);
    }
    while (!qn.empty())
    {
        int sz=qn.size();
        res++;
        for (size_t i = 0; i < sz; i++)
        {
            Node * cur=qn.front();
            qn.pop();
            for (int j = 0; j < cur->children.size(); j++)
            {
                if (cur->children[j]!=nullptr)
                {
                    qn.push(cur->children[j]);
                }
                
            }
            
        }
    }
    return res;   
    
}