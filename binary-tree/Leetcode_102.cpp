#include "iostream"
#include "queue"
#include "vector"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        int q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        res.push_back(temp);
    }
    return res;
}