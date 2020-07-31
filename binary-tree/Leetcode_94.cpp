#include "iostream"
#include "stack"
#include "vector"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void curr(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    curr(root->left, res);
    res.push_back(root->val);
    curr(root->right, res);
}

vector<int> inorderTraversal1(TreeNode *root)
{
    vector<int> res;
    curr(root, res);
    return res;
}

vector<int> inorderTraversal(TreeNode *root)
{
    if (!root)
        return {};
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *current = root;
    while (!s.empty() || current)
    {
        if(current)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            current = s.top();
            s.pop();
            res.push_back(current->val);
            current = current->right;
        }
    }
    return res;
}