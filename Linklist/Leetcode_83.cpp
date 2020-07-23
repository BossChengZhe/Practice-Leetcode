#include "iostream"
#include "vector"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *p = new ListNode(INT_MAX);
    p->next = head;
    head = p;
    p = head->next;
    ListNode *q = p->next;
    p->next = NULL;
    while (q)
    {
        if (q->val == p->val)
        {
            while (q && q->val == p->val)
                q = q->next;
            if(!q)
                break;
        }
        p->next = q;
        q = q->next;
        p = p->next;
        p->next = nullptr;
    }
    return head->next;
}