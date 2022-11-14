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

void getPath(TreeNode *root, vector<int> &path, vector<string> &res)
{
    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
        string temp;
        int i = 0;
        for (; i < path.size() - 1; i++)
        {
            string s = to_string(path[i]) + "->";
            temp += s;
        }
        temp+=to_string(path[i]);
        res.push_back(temp);
        return;
    }
    if (root->left)
    {
        getPath(root->left, path, res);
        path.pop_back();
    }
    if (root->right)
    {
        getPath(root->right, path, res);
        path.pop_back();
    }
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> res;
    vector<int> path;
    if (root == nullptr)
    {
        return res;
    }
    getPath(root, path, res);
    return res;
}
int main()
{
}