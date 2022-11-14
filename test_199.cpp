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
vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    queue<TreeNode *> trq;
    if (root != nullptr)
    {
        trq.push(root);
    }
    while (!trq.empty())
    {
        int size = trq.size();
        TreeNode *cur;
        for (int i = 0; i < size; i++)
        {
            cur = trq.front();
            trq.pop();
            if (cur->left)
            {
                trq.push(cur->left);
            }
            if (cur->right)
            {
                trq.push(cur->right);
            }
        }
        res.push_back(cur->val);
    }
    return res;
}
int main()
{
}