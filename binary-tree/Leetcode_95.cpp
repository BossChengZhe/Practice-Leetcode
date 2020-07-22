#include "iostream"
#include "vector"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> curr(int l, int r)
{
    vector<TreeNode *> res;
    if(l > r)
        return {};
    for(int i = l; i <= r; i++)
    {
        for(auto & left:curr(l, i-1))
        {
            for(auto & right:curr(i+1,r))
            {
                TreeNode *root = new TreeNode(i, left, right);
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n)
{
    if(!n)
        return {};
    return curr(1, n);
}

