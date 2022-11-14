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
int maxDepth(TreeNode *root)
{
    int res = 0;
    queue<TreeNode *> qt;
    if (root!=nullptr)
    {
        qt.push(root);
    }
    while (!qt.empty())
    {
        int size = qt.size();
        res++;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode *cur = qt.front();
            qt.pop();
            if (cur->left)
            {
                qt.push(cur->left);
            }
            if (cur->right)
            {
                qt.push(cur->right);
            }
        }
    }
    return res;
}
int maxDepth(TreeNode *root){
    if (root==nullptr)
    {
        return 0;
    }
    int leftd=maxDepth(root->left);
    int rightd=maxDepth(root->right);
    return 1+max(leftd,rightd);
}
int main()
{
}