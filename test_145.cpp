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
void houxu(TreeNode *root,vector<int> &res){
    if (root==nullptr)
    {
        return;
    }
    houxu(root->left,res);
    houxu(root->right,res);
    res.push_back(root->val);
    
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int>res;
    houxu(root,res);
    return res;
}
int main()
{

}