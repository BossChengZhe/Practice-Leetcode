#include "iostream"
#include "vector"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool curr(TreeNode *root, int upper, int lower)
{
    if (root == 0)
        return true;
    if (root->val >= upper || root->val <= lower)
        return false;
    return curr(root->left, root->val, lower) && curr(root->right, upper, root->val);
}

bool judge(TreeNode *root, long long &x)
{
    if (root == 0)
        return true;
    if (!judge(root->left, x) || root->val <= x)
        return false;
    x = root->val;
    if (!judge(root->right, x))
        return false;
    return true;
}

bool isValidBST(TreeNode *root)
{
    long long x = LONG_MIN;
    return judge(root, x);
}