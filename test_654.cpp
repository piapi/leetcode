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
TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    TreeNode *root = new TreeNode(0);
    if (nums.size() == 1)
    {
        root->val = nums[0];
        return root;
    }

    int index = 0;
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
            index = i;
        }
    }
    root->val = max;
    if (index > 0)
    {
        vector<int> leftn(nums.begin(), nums.begin() + index);
        root->left = constructMaximumBinaryTree(leftn);
    }

    if (index < (nums.size() - 1))
    {
        vector<int> rightn(nums.begin() + index + 1, nums.end());
        root->right = constructMaximumBinaryTree(rightn);
    }

    return root;
}

int main()
{
}