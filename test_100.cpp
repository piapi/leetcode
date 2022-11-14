#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return 1;
    }
    if (p == nullptr || q == nullptr)
    {
        return 0;
    }
    queue<TreeNode *> qt1;
    queue<TreeNode *> qt2;
    qt1.push(p);
    while (!qt1.empty())
    {
        int sz = qt1.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = qt1.front();
            qt1.pop();
            qt2.push(cur);
            if (cur != nullptr)
            {
                qt1.push(cur->left);
                qt1.push(cur->right);
            }
            else
            {
                continue;
            }
        }
    }
    qt1 =queue<TreeNode *>();
    qt1.push(q);
    while (!qt1.empty())
    {
        int sz = qt1.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = qt1.front();
            qt1.pop();
            TreeNode *com=qt2.front();
            qt2.pop();
            if (cur==nullptr && com==nullptr)
            {
                continue;
            }
            
            
            if (cur==nullptr || com==nullptr || cur->val!=com->val)
            {
                return false;
            }
            
            if (cur != nullptr)
            {
                qt1.push(cur->left);
                qt1.push(cur->right);
            }
        }
    }
    return true;
}
int main()
{
}