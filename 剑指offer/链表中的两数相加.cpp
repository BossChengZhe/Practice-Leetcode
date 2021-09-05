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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up = 0;
        stack<int> s1, s2;
        ListNode *p = l1;
        while(p) {
            s1.push(p->val);
            p = p->next;
        }
        p = l2;
        while(p) {
            s2.push(p->val);
            p = p->next;
        }

        ListNode *head = new ListNode(1);
        while(!s1.empty() && !s2.empty()) {
            int temp = s1.top() + s2.top() + up;
            up = temp / 10;
            ListNode *tx = new ListNode(temp % 10);
            tx->next = head->next;
            head->next = tx;
            s1.pop(); 
            s2.pop();
        }
        while(!s1.empty()) {
            int temp = s1.top() + up;
            up = temp / 10;
            ListNode *tx = new ListNode(temp % 10);
            tx->next = head->next;
            head->next = tx;
            s1.pop();
        }
        while(!s2.empty()) {
            int temp = s2.top() + up;
            up = temp / 10;
            ListNode *tx = new ListNode(temp % 10);
            tx->next = head->next;
            head->next = tx;
            s2.pop();
        }
        if(up) {
            ListNode *tx = new ListNode(up);
            tx->next = head->next;
            head->next = tx;
        }
        return head->next;
    }
};