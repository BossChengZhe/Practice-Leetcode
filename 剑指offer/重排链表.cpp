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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode *temp = head;
        head = head->next;
        temp->next = nullptr;
        while(head) {
            ListNode *q = head->next;
            head->next = temp;
            temp = head;
            head = q;
        }
        return temp;
    }
    void reorderList(ListNode* head) {
        if(!head)
            return;
        // 快慢指针判断中点
        ListNode *quick = head, *slow = head;
        while(quick) {
            quick = quick->next;
            if(!quick)
                break;
            quick = quick->next;
            if(quick)
                slow = slow->next;
        }


        ListNode * headright = new ListNode(1, slow->next);
        slow->next = nullptr;
        headright->next = reverseList(headright->next);

        ListNode *q = headright->next, *curr = head;
        while(q) {
            ListNode *temp = q->next;
            q->next = curr->next;
            curr->next = q;
            q = temp;
            curr = curr->next;
            curr = curr->next;
        }
        return;
    }
};