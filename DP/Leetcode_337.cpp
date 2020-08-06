#include "iostream"
#include "vector"
#include "unordered_map"
#include "cmath"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<TreeNode *, int> f, g;

void curr2(TreeNode *root)
{
    if(!root)
        return;
    curr2(root->left);
    curr2(root->right);
    f[root] = g[root->left] + g[root->right]+root->val;
    g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right])+root->val;
}

int rob2(TreeNode *root)
{
    curr2(root);
    return max(f[root], g[root]);
}

vector<int> curr(TreeNode *root)
{
    if(!root)
        return {0, 0};
    auto l = curr(root->left);
    auto r = curr(root->right);
    int selected = root->val + l[1] + r[1];
    int unselected = max(l[0], l[1]) + max(r[0], r[1]);
    return {selected, unselected};
}