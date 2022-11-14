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
    
    if (root==nullptr ||(root->val-p->val>=0 && root->val-q->val<=0) || (root->val-p->val<=0 && root->val-q->val>=0))
    {
        return root;
    }
   
    
    
    TreeNode * leftN=lowestCommonAncestor(root->left,p,q);
    TreeNode * rightN=lowestCommonAncestor(root->right,p,q);
    if (leftN==nullptr && rightN==nullptr)
    {
        return nullptr;
    }
    if (leftN==nullptr)
    {
        return rightN;
    }
    if (rightN==nullptr)
    {
        return leftN;
    }
    
    return root;
}
int main()
{
}