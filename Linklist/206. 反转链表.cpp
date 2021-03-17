#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(!head)
            return nullptr;
        ListNode *q = head->next;
        head->next = nullptr;
        while (q)
        {
            ListNode *temp = q->next;
            q->next = head;
            head = q;
            q = temp;
        }
        return head;
    }
};