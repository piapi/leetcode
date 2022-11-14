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

int getMinimumDifference(TreeNode *root)
{
    queue<TreeNode *> qn;
    vector<int> arr;
    int res=0;
    qn.push(root);
    while (!qn.empty())
    {
        int sz = qn.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = qn.front();
            qn.pop();
            arr.push_back(cur->val);
            if (cur->left)
            {
                qn.push(cur->left);
            }
            if (cur->right)
            {
                qn.push(cur->right);
            }
        }
    }
    sort(arr.begin(),arr.end());
    res=arr[1]-arr[0];
    for (int i = 2; i < arr.size(); i++)
    {
        res=min(res,arr[i]-arr[i-1]);
    }
    return res;
}
int main()
{
}