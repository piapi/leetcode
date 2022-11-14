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
void hasSum(TreeNode *root, int &curSum, vector<int> &Sums)
{
    curSum += root->val;
    if (root->left == nullptr && root->right == nullptr)
    {
        Sums.push_back(curSum);
        return;
    }
    if (root->left)
    {
        hasSum(root->left, curSum, Sums);
        curSum -= root->left->val;
    }
    if (root->right)
    {
        hasSum(root->right, curSum, Sums);
        curSum -= root->right->val;
    }
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    int sum = 0;
    if (root==nullptr)
    {
        return false;
    }
    
    vector<int> Sums;
    hasSum(root, sum, Sums);
    for (int s : Sums)
    {
        if (s == targetSum)
        {
            return true;
        }
    }

    return false;
}
int main()
{
}