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
};