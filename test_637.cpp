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
vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> res;
    queue<TreeNode*>trq;
    if (root!=nullptr)
    {
        trq.push(root);
    }
    while (!trq.empty())
    {
        int size=trq.size();
        double temp=0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *cur=trq.front();
            trq.pop();
            temp+=cur->val;
            if (cur->left)
            {
                trq.push(cur->left);
            }
            if (cur->right)
            {
                trq.push(cur->right);
            }
        }
        res.push_back(temp/size);
    }
    return res;
}
int main()
{
}