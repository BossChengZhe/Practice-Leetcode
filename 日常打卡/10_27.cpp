#include "iostream"
#include "stack"
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

vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    vector<int> res;
    s.push(root);
    if (root == 0)
        return {};
    while (!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        res.push_back(node->val);
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
    return res;
}