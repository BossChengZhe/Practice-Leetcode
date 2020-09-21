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

void curr(TreeNode *root, int &sum)
{
    if(!root)
        return;
    curr(root->right, sum);
    sum += root->val;
    root->val = sum;
    curr(root->left, sum);
}

TreeNode *convertBST(TreeNode *root)
{
    int sum = 0;
    curr(root, sum);
    return root;
}