#include "iostream"
#include "vector"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void curr(TreeNode* &root, vector<int> &temp, int start, int end)
{
    if (start>end)
        return;
    else if (start==end)
    { 
        root = new TreeNode(temp[start]);
        return;
    }
    int mid = start + (end-start)/2;
    root = new TreeNode(temp[mid]);
    curr(root->left, temp, start, mid - 1);
    curr(root->right, temp, mid + 1, end);
}

TreeNode* sortedListToBST1(ListNode* head) {
    vector<int> temp;
    while(head)
    { 
        temp.push_back(head->val);
        head = head->next;
    }
    TreeNode * root = nullptr;
    curr(root, temp, 0, temp.size()-1);
    return root;
}

// 方法二
int get_length(ListNode *head)
{
    int res=0;
    while(head)
    {
        res ++;
        head = head->next;
    }
    return res;
} 

TreeNode* build(ListNode* &head, int left, int right)
{
    if(left  > right)
        return nullptr;
    int mid = left + (right-left) / 2;
    TreeNode* root = new TreeNode(head->val);
    root->left = build(head, left, mid-1);
    head = head->next;
    root->right = build(head, mid + 1, right);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    return build(head, 0, get_length(head)-1);
}