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
int maxVal = INT32_MIN; // 因为后台测试数据中有int最小值
bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;

    bool left = isValidBST(root->left);
    // 中序遍历，验证遍历的元素是不是从小到大
    if (maxVal < root->val)
        maxVal = root->val;
    else
        return false;
    bool right = isValidBST(root->right);

    return left && right;
}
int main()
{
}