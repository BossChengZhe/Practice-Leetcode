#include "iostream"
#include "vector"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    if(!head)
        return NULL;
    ListNode *p = head, *q = head->next;
    ListNode *NewHead = new ListNode(0, head);
    ListNode *k = NewHead;
    if(!q)
        return p;
    while(p&&q)
    {
        p->next = q->next;
        q->next = p;
        k->next = q;
        k = p;
        p = p->next;
        if(!p)
            break;
        if(!p->next)
        {
            k->next = p;
            break;
        }
        q = p->next;
    }
    k = NewHead->next;
    delete NewHead;
    return k;
}