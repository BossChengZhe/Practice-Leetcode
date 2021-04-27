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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *temp_head = new ListNode(INT_MAX, head);
        ListNode *pre = nullptr, *last = nullptr, *current = temp_head;
        int cnt = 0;
        while (temp_head)
        {
            cnt++;
            if (cnt == left)
                pre = temp_head;
            if (cnt == right + 1)
            {
                last = temp_head;
                break;
            }
            temp_head = temp_head->next;
        }

        temp_head = current;
        current = pre->next;
        cout << current->val << endl;
        pre->next = last->next;
        last->next = nullptr;
        while (current)
        {
            ListNode *p = current->next;
            current->next = pre->next;
            pre->next = current;
            current = p;
        }
        return temp_head->next;
    }
};