#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp_head = new ListNode(INT_MAX, head);
        ListNode *quick = head, *slow = temp_head;
        while(quick) {
            if(n)
                n--;
            else
                slow = slow->next;
            quick = quick->next;
        }
        ListNode *del_node = slow->next;
        slow->next = del_node->next;
        del_node->next = nullptr;
        delete del_node;
        return temp_head->next;
    }
};