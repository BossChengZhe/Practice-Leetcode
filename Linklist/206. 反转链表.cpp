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
        ListNode *temp_head = new ListNode(INT_MAX, nullptr);
        while(head)
        {
            ListNode *p = head->next;
            head->next = temp_head->next;
            temp_head->next = head;
            head = p;
        }
        return temp_head->next;
    }
};