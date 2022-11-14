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
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr)
    {
        return root2;
    }
    if (root2 == nullptr)
    {
        return root1;
    }
    queue<TreeNode *> q1;

    q1.push(root1);
    q1.push(root2);
    while (!q1.empty())
    {
        TreeNode *t1 = q1.front();
        q1.pop();
        TreeNode *t2 = q1.front();
        q1.pop();
        t1->val = t1->val + t2->val;
        if (t1->left != nullptr && t2->left != nullptr)
        {
            q1.push(t1->left);
            q1.push(t2->left);
        }
        if (t1->right!=nullptr && t2->right!=nullptr)
        {
            q1.push(t1->right);
            q1.push(t2->right);
        }
        if (t1->left==nullptr && t2->left != nullptr)
        {
            t1->left=t2->left;
        }
        if (t1->right==nullptr && t2->right != nullptr)
        {
            t1->right=t2->right;
        }
    }
    return root1;
}
int main()
{
}