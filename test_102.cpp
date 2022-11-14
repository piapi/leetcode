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
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> tr;
    if (root != nullptr)
    {
        tr.push(root);
    }

    while (!tr.empty())
    {
        vector<int> temp;
        int size = tr.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *t = tr.front();
            temp.push_back(t->val);
            tr.pop();
            if (t->left)
                tr.push(t->left);
            if (t->right)
                tr.push(t->right);
        }
        res.push_back(temp);
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
}