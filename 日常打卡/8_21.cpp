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

int minDepth(TreeNode *root)
{
    if(!root)
        return 0;
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        int len = q.size();
        res++;
        for(int i = 0; i < len; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            if(!node->left && !node->right)
                return res;
        }
    }
    return -1;
}