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
int countNodes(TreeNode *root)
{
    int res = 0;
    queue<TreeNode *> que;
    if (root != nullptr)
    {
        que.push(root);
    }
    while (!que.empty())
    {
        int sz = que.size();
        res+=sz;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = que.front();
            que.pop();
            if (cur->left)
            {
                que.push(cur->left);
            }
            if (cur->right)
            {
                que.push(cur->right);
            }
        }
    }
    return res;
}
int main()
{
}