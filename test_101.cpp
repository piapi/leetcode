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
bool isSymmetric(TreeNode *root)
{
    queue<TreeNode *> qt;

    if (root == nullptr || (!root->left && !root->right))
    {
        return true;
    }
    else if ((root->left && !root->right) || (!root->left && root->right) || (root->left->val != root->right->val))
    {
        return false;
    }
    qt.push(root->left);
    qt.push(root->right);

    while (!qt.empty())
    {
        int sz = qt.size();
        TreeNode * left=qt.front();
        qt.pop();
        TreeNode *right=qt.front();
        qt.pop();
        if (left==nullptr && right==nullptr)
        {
            continue;
        }
        if ((left==nullptr ^ right==nullptr) || right->val!=left->val)
        {
            return false;
        }
        qt.push(left->left);
        qt.push(right->right);
        qt.push(left->right);
        qt.push(right->left);
    }
    return true;
}
int main()
{
}