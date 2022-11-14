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
void zhongxu(TreeNode *root,vector<int> &res){
    if (root==nullptr)
    {
        return;
    }
    
    zhongxu(root->left,res);
    res.push_back(root->val);
    zhongxu(root->right,res);
    
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int>res;
    zhongxu(root,res);
    return res;
}
int main()
{

}