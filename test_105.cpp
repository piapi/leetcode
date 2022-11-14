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
TreeNode *traversal(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0)
    {
        return nullptr;
    }
    int rootVal = preorder[0];
    TreeNode *root = new TreeNode(rootVal);

    int index = 0;
    for (; index < inorder.size(); index++)
    {
        if (inorder[index] == rootVal)
        {
            break;
        }
    }

    preorder = vector<int>(preorder.begin() + 1, preorder.end());
    vector<int> left_in(inorder.begin(), inorder.begin() + index);
    vector<int> right_in(inorder.begin() + index + 1, inorder.end());

    vector<int> left_pre(preorder.begin(),preorder.begin()+left_in.size());
    vector<int> right_pre(preorder.begin()+left_in.size(),preorder.end());

    root->left=traversal(left_pre,left_in);
    root->right=traversal(right_pre,right_in);
    return root;

}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return traversal(preorder, inorder);
}
int main()
{
}