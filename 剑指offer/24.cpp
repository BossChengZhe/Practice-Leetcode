#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(!head)
            return NULL;
        ListNode *p = head->next;
        head->next = nullptr;
        while(p)
        {
            ListNode *q = head;
            head = p;
            p = p->next;
            head->next = q;
        }
        return head;
    }
};