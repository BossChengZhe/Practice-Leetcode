#include "algorithm"
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};
    bool flag = false;
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> res;
    while (q.empty())
    {
        int size_q = q.size();
        vector<int> temp;
        for (int i = 0; i < size_q; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        if(flag)
            reverse(temp.begin(), temp.end());
        flag = flag ? false : true;
        res.push_back(temp);
    }
    return res;
}