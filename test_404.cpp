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
int sumOfLeftLeaves(TreeNode *root)
{
    queue<TreeNode *> qt;
    if (root==nullptr)
    {
        return 0;
    }
    int res=0;
    qt.push(root);
    while (!qt.empty())
    {
        int sz=qt.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode * cur=qt.front();
            qt.pop();
            if (cur->left)
            {
                if (cur->left->left==nullptr && cur->left->right==nullptr)
                {
                    res+=cur->left->val;
                }
                
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

int sumOfLeftLeaves(TreeNode *root)
{
    int res=0;
    if (root==nullptr || (root->left==nullptr && root->right==nullptr))
    {
        return 0;
    }
    res+=sumOfLeftLeaves(root->left);
    if (root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr)
    {
        res+= root->left->val;
    }
    
    res+=sumOfLeftLeaves(root->right);
    return res;
}
int main()
{
}