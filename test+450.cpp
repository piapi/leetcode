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


TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root==nullptr)
    {
        return root;
    }
    if (root->val==key)
    {
        if (root->left==nullptr && root->right==nullptr)
        {
            return nullptr;
        }
        if (root->left==nullptr && root->right!=nullptr)
        {
            return root->right;
        }
        if (root->left!=nullptr && root->right==nullptr)
        {
            return root->left;
        }
        if (root->left!=nullptr && root->right!=nullptr)
        {
            TreeNode * rr=root->right;
            while (rr->left!=nullptr)
            {
                rr=rr->left;
            }
            rr->left=root->left;
            TreeNode *temp=root;
            root=root->right;
            return root;
        }
        
        
    }
    if (root->val>key)
    {
        root->left=deleteNode(root->left,key);
    }else{
        root->right=deleteNode(root->right,key);
    }
    
    return root;
}
int main()
{
}