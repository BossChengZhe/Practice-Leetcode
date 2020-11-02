#include "iostream"
#include "vector"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    while(p && q)
    {
        p = p->next;
        q = q->next;
        if(!q)
            return false;
        q = q->next;
        if(p==q)
            return true;
    }
    return false;
}