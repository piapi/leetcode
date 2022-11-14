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
void hasSumPath(TreeNode *root, int &curSum, vector<int> &p, vector<vector<int>> &paths,int target)
{
    curSum += root->val;
    p.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
        if (curSum==target)
        {
            paths.push_back(p);
        }
        return;
    }
    if (root->left)
    {
        hasSumPath(root->left,curSum,p,paths,target);
        p.pop_back();
        curSum-=root->left->val;
    }
    if (root->right)
    {
        hasSumPath(root->right,curSum,p,paths,target);
        p.pop_back();
        curSum-=root->right->val;
    }
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> res;
    if (root==nullptr)
    {
        return res;
    }
    int curs=0;
    vector<int> p;
    hasSumPath(root,curs,p,res,targetSum);
    return res;
}
int main()
{
}