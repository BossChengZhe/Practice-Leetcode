#include "iostream"
#include "vector"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x)
{
    if(!head)
        return nullptr;
    ListNode *left = new ListNode(INT_MIN);
    ListNode *res = left;
    ListNode *right = new ListNode(INT_MAX);
    ListNode *temp_r = right;
    while (head)
    {
        ListNode *temp = head;
        temp = temp->next;
        if (head->val < x)
        {
            left->next = head;
            left = head;
            left->next = NULL;
        }
        else
        {
            right->next = head;
            right = head;
            right->next = NULL;
        }
        head = temp->next;
    }
    left->next = temp_r->next;
    return res->next;
}