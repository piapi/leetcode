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
int temp = 0;
TreeNode *convertBST(TreeNode *root)
{
    if (root == nullptr)
    {
        return root;
    }
    root->right = convertBST(root->right);
    temp += root->val;
    root->val = temp;
    root->left = convertBST(root->left);
    return root;
}
int main()
{
}