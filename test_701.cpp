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
TreeNode *insertIntoBST(TreeNode *root, int val)
{

    if (root == NULL)
    {
        TreeNode *node = new TreeNode(val);
        return node;
    }
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    if (root->val < val)
        root->right = insertIntoBST(root->right, val);
    return root;
}
int main()
{
}