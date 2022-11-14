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
bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second; 
}

unordered_map<int, int> ump;
void diedai(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    diedai(root->left);
    ump[root->val] += 1;
    diedai(root->right);
}
vector<int> findMode(TreeNode *root)
{
    diedai(root);
    vector<pair<int, int>> vec(ump.begin(), ump.end());
    sort(vec.begin(), vec.end(), cmp); 
    vector<int> res;
    res.push_back(vec[0].first);
    for (int i = 1; i < vec.size(); i++)
    {
        
        if (vec[i].second == vec[0].second)
            res.push_back(vec[i].first);
        else
            break;
    }
    return res;
}
int main()
{
}