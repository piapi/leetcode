#include <iostream>
#include <vector>
// https://baijiahao.baidu.com/s?id=1736339086704827934&wfr=spider&for=pc
using namespace std;

class SegmentTreeNode
{
private:
    /* data */
public:
    SegmentTreeNode(int start, int end, int max)
    {
        this->start = start;
        this->end = end;
        this->max = max;
    }
    int start, end, max;
    SegmentTreeNode *left, *right;
};

class SegmentTree
{
private:
    /* data */
    SegmentTreeNode *stRoot;
    int stQuery(SegmentTreeNode *root, int start, int end)
    {
        if (start <= root->start && end >= root->end)
        {
            return root->max;
        }
        int mid = (root->start + root->end) / 2;
        int res = INT16_MIN;
        if (mid >= start)
        {
            res = max(res, stQuery(root->left, start, end));
            // cout << res << "\n";
        }
        if (mid + 1 <= end)
        {
            res = max(res, stQuery(root->right, start, end));
            // cout << res << "\n";
        }

        return res;
    }
    void stUpdate(SegmentTreeNode *root, int nIdx, int nVal)
    {
        if (root->start == root->end && root->start == nIdx)
        {
            /* code */
            root->max = nVal;
            return;
        }
        int mid = (root->start + root->end) / 2;
        // cout << root->start << "-" << root->end << "\t";

        if (nIdx <= mid)
        {
            stUpdate(root->left, nIdx, nVal);
        }
        else
        {
            stUpdate(root->right, nIdx, nVal);
        }
        // cout<<root->max<<"\n";
        root->max = max(root->left->max, root->right->max);
    }
    SegmentTreeNode *build(int *array, int start, int end)
    {
        if (start > end)
            return NULL;
        SegmentTreeNode *root = new SegmentTreeNode(start, end, array[start]);
        if (start == end)
        {
            // cout<<start<<"-"<<end<<"\n";
            return root;
        }
        int mid = (start + end) / 2;
        root->left = build(array, start, mid);
        root->right = build(array, mid + 1, end);
        root->max = max(root->left->max, root->right->max);
        // cout<<start<<"-"<<end<<"\n";
        return root;
    }

public:
    SegmentTree(int *array, int len)
    {
        stRoot = NULL;
        stRoot = build(array, 0, len - 1);
    }
    ~SegmentTree();

    int Query(int start, int end)
    {
        return stQuery(stRoot, start, end);
    }
    void Update(int nIdx, int nVal)
    {
        stUpdate(stRoot, nIdx, nVal);
    }
};

int main()
{
    int array[] = {2, 3, 1, 6, 4, 8, 9};
    SegmentTreeNode *stn = new SegmentTreeNode(0, 7, array[0]);
    SegmentTree *st = new SegmentTree(array, 7);

    cout << st->Query(2, 4) << "\n";
    st->Update(4, 100);
    cout << st->Query(2, 4) << "\n";
    cout << st->Query(0, 6) << "\n";
    // cout << stn->start << "\t" << stn->max << "\n";
}
