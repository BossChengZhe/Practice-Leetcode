#include "iostream"
#include "vector"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    ListNode *temp = head;
    int len = 0;
    while(temp)
    {
        temp = temp->next;
        len++;
    }
    k %= len;
    temp = head;
    for(int i = 1; i < len-k; i++)
        temp = temp->next;
    ListNode *rr = temp;
    for(int i = 0; i < k; i++)
        rr = rr->next;
    temp->next = NULL;
    rr->next = head;
    return rr;
}