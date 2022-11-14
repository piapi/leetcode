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
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == val)
    {
        return root;
    }
    if (root->val < val)
    {
        return searchBST(root->right, val);
    }
    if (root->val > val)
    {
        return searchBST(root->left, val);
    }
    return nullptr;
}
int main()
{
}