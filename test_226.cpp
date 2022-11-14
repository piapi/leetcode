#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *invertTree(TreeNode *root)
{
    queue<TreeNode *> qt;
    if (root != nullptr)
    {
        qt.push(root);
    }
    while (!qt.empty())
    {
        int size=qt.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * cur=qt.front();
            qt.pop();
            TreeNode *temp=cur->left;
            cur->left=cur->right;
            cur->right=temp;
            if (cur->left!=nullptr)
            {
               qt.push(cur->left);
            }
            if (cur->right!=nullptr)
            {
               qt.push(cur->right);
            }
        }
        
    }
    return root;
}
int main()
{
}