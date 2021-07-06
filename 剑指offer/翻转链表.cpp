#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 使用虚拟头结点
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *temp_head = new ListNode(INT_MAX);
        temp_head->next = head;
        ListNode *p = head->next;
        head->next = nullptr;

        while (p)
        {
            ListNode *q = p->next;
            p->next = temp_head->next;
            temp_head->next = p;
            p = q;
        }
        return temp_head->next;
    }
};

// 不使用额外空间，实习腾讯面试被要求过不使用额外空间，本人是很喜欢加一个头结点的，其实差别不大
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *p = head->next;
        head->next = nullptr;
        while (p)
        {
            ListNode *q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};