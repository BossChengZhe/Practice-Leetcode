#include "iostream"
#include "vector"
#include "queue"
#include "cmath"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root)
{
    if(!root)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int maxDepth_level(TreeNode *root)
{
    if(!root)
        return 0;
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        int q_size = q.size();
        res++;
        for(int i = 0; i < q_size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    return res;
}