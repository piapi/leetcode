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
    qt1 = queue<TreeNode *>();
    qt1.push(q);
    while (!qt1.empty())
    {
        int sz = qt1.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = qt1.front();
            qt1.pop();
            TreeNode *com = qt2.front();
            qt2.pop();
            if (cur == nullptr && com == nullptr)
            {
                continue;
            }

            if (cur == nullptr || com == nullptr || cur->val != com->val)
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
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    queue<TreeNode *> qr;
    qr.push(root);
    while (!qr.empty())
    {
        int sz = qr.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = qr.front();
            qr.pop();
            if (isSameTree(cur, subRoot))
            {
                return true;
            }
            if (cur->left)
            {
                qr.push(cur->left);
            }
            if (cur->right)
            {
                qr.push(cur->right);
            }
        }
    }
    return false;
}
int main()
{
    queue<int> q1;
    for (size_t i = 0; i < 5; i++)
    {
        q1.push(i);
    }
    queue<int> q2 = q1;
    while (!q2.empty())
    {
        q2.pop();
    }
    cout << q1.size() << endl;
    cout << q2.size() << endl;
}