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

void cur(TreeNode *&root, vector<int> &nums, int left, int right)
{
    int n = nums.size();
    if (left < 0 || right >= n || left > right)
        return;
    int mid = (left + right) >> 1;
    root = new TreeNode(nums[mid]);
    cur(root->left, nums, left, mid - 1);
    cur(root->right, nums, mid + 1, right);
    return;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
        return NULL;
    TreeNode *root;
    cur(root, nums, 0, nums.size() - 1);
    return root;
}