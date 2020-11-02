#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"
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

vector<int> postorderTraversal(TreeNode *root)
{
    if(root==nullptr)
        return {};
    stack<TreeNode *> s;
    vector<int> res;
    s.push(root);
    while(!s.empty())
    {
        TreeNode *tmp = s.top();
        s.pop();
        res.push_back(tmp->val);
        if(tmp->left)
            s.push(tmp->left);
        if(tmp->right)
            s.push(tmp->right);
    }
    reverse(res.begin(), res.end());
    return res;
}