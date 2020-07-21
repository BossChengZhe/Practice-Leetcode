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
    if (!head)
        return nullptr;
    ListNode *p = new ListNode(INT_MIN);
    p->next = head;
    head = p;
    p = head->next;
    ListNode *q = p->next, *flag = head;

    while (q)
    {
        cout << p->val << " " << q->val << endl;
        if (p->val == q->val)
        {
            while (q && q->val == p->val)
                q = q->next; 
            if (!q || q->next==nullptr)
            {
                flag->next = q;
                break;
            }
        }
        else
        {
            if(q->next==NULL)
            {
                flag->next = p;
                flag = flag->next;
                flag->next = q;
                break;
            }
            flag->next = p;
            flag = flag->next;
            flag->next = NULL;
        }
        p = q;
        q = q->next;
    }
    return head->next;
}