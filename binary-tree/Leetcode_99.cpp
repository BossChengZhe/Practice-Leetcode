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

void swap(vector<TreeNode *> &res)
{
    int x;
    if (res.size() == 2)
        x = 1;
    else
        x = 3;
    long long temp = res[0]->val;
    res[0]->val = res[x]->val;
    res[x]->val = temp;
}

void curr(TreeNode *root, vector<TreeNode *> &res, long long &pre, TreeNode *&father)
{
    if (root == 0)
        return;
    curr(root->left, res, pre, father);
    if (root->val <= pre)
    {
        res.push_back(father);
        res.push_back(root);
    }
    father = root;
    pre = root->val;
    curr(root->right, res, pre, father);
}

void recoverTree2(TreeNode *root)
{
    vector<TreeNode *> res;
    long long pre = LONG_MIN;
    TreeNode *father = nullptr;
    curr(root, res, pre, father);
    swap(res);
    return;
}

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) {
                            x = pred;
                        }
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};