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
TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
{
    if (postorder.size() == 0) return nullptr;
     int rootValue = postorder[postorder.size() - 1];
     TreeNode *root = new TreeNode(rootValue);
     if (postorder.size()==1)
     {
        return root;
     }
     int index=0;
     for ( ; index <inorder.size(); index++)
     {
        if (rootValue==inorder[index])
        {
            break;
        }
     }

     vector<int> left_in(inorder.begin(),inorder.begin()+index);
     vector<int> right_in(inorder.begin()+index+1,inorder.end());

     postorder.resize(postorder.size()-1);
     vector<int>  left_post(postorder.begin(),postorder.begin()+left_in.size());
     vector<int> right_post(postorder.begin()+left_in.size(),postorder.end());

     root->left=traversal(left_in,left_post);
     root->right=traversal(right_in,right_post);

     return root;
     
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return traversal(inorder,postorder);
}
int main()
{
}