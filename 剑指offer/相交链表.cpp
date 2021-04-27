#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    // 若相交，会在交汇点相遇，否则只能在尾部相遇
    {
        ListNode *tempA = headA, *tempB = headB;
        while (headA!=headB)
        {
            headA = headA == nullptr ? tempB : headA->next;
            headB = headB == nullptr ? tempA : headB->next;
        }
        return headA;
    }
};