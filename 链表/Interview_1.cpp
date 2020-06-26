#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeDuplicateNodes(ListNode *head)
{
    if(!head)
        return NULL;
    ListNode *tmp_head = head, *p = head;
    head = head->next;
    unordered_set<int> us;
    while(head)
    {
        ListNode *q = head;
        head = head->next;
        if(us.find(q->val)!=us.end())
        {
            us.emplace(q->val);
            p = p->next;
        }
        else{
            p->next = q->next;
            delete q;
        }
    }
    return tmp_head;
}