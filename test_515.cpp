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
vector<int> largestValues(TreeNode *root)
{
    vector<int> res;
    queue<TreeNode *> tq;
    if (root != nullptr)
    {
        tq.push(root);
    }
    while (!tq.empty())
    {
        int max = INT32_MIN;
        int size = tq.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *cur = tq.front();
            tq.pop();
            max = max > cur->val ? max : cur->val;
            if (cur->left)
            {
                tq.push(cur->left);
            }
            if (cur->right)
            {
                tq.push(cur->right);
            }
        }
        res.push_back(max);
    }
    return res;
}
int main()
{
}