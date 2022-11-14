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
int findM(TreeNode *root){
    if (root==nullptr)
    {
        return 0;
    }
    int leftx=findM(root->left);
    if (leftx==-1)
    {
        return -1;
    }
    int rightx=findM(root->right);
    if (rightx==-1)
    {
        return -1;
    }
     return abs(leftx - rightx) > 1 ? -1 : 1 + max(leftx, rightx);
    
}
bool isBalanced(TreeNode *root)
{
    if (findM(root)==-1)
    {
        return 0;
    }
    return 1;
}
int main()
{
}