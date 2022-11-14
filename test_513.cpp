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
int findBottomLeftValue(TreeNode *root)
{
    queue<TreeNode *> qt;
    qt.push(root);
    int res;
    while (!qt.empty())
    {
        int sz=qt.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode * cur=qt.front();
            qt.pop();
            if(i==0){
                res=cur->val;
            }
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
int main()
{
}