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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp_head = new ListNode(INT_MAX);
        ListNode *temp = temp_head;
        int pre = INT_MAX;
        while (head)
        {
            if (head->val != pre)
            {
                pre = head->val;
                temp->next = head;
                head = head->next;
                temp = temp->next;
                temp->next = nullptr;
            }
            else
            {
                ListNode *x;
                x = head;
                head = head->next;
                delete x;
            }
        }
        temp = temp_head->next;
        delete temp_head;
        return temp;
    }
};