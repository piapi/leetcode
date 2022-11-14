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
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return new TreeNode(nums[0]);
    }

    int mid = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    vector<int> leftn(nums.begin(), nums.begin() + mid);
    root->left = sortedArrayToBST(leftn);
    if (nums.size() > 2)
    {
        vector<int> rightn(nums.begin() + mid + 1, nums.end());
        root->right = sortedArrayToBST(rightn);
    }

    return root;
}
int main()
{
}