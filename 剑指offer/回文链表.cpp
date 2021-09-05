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
    bool isPalindrome(ListNode* head) {
        // 寻找中点
        if(!head)
            return true;
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

        quick = slow->next;
        slow->next = nullptr;
        slow = quick;
        slow = reverseList(slow);

        while(slow && head) {
            if(slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};