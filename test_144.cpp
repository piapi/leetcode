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
void qianxu(TreeNode *root,vector<int> res){
    if (root==nullptr)
    {
        return;
    }
    res.push_back(root->val);
    qianxu(root->left,res);
    qianxu(root->right,res);
    
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int>res;
    qianxu(root,res);
    return res;
}
int main()
{
    TreeNode *root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int> res=preorderTraversal(root);
}