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
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root == p || root == q)
    {
        return root;
    }
    TreeNode *ln = lowestCommonAncestor(root->left, p, q);
    TreeNode *rn = lowestCommonAncestor(root->right, p, q);
    if (ln == nullptr && rn == nullptr)
    {
        return nullptr;
    }
    if (ln == nullptr)
    {
        return rn;
    }
    if (rn == nullptr)
    {
        return ln;
    }
    if (rn != nullptr && ln != nullptr)
    {
        return root;
    }

    return root;
}
int main()
{
}