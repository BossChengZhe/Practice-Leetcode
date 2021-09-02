#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        
        ListNode *quick = head, *slow = head;

        do{
            quick = quick->next;
            slow = slow->next;
            if(quick == nullptr)
                return nullptr;
            quick = quick->next;
        } while (quick && quick != slow);

        if(quick == nullptr)
            return nullptr;
        ListNode *res = head;
        while(res != slow)
        {
            res = res->next;
            slow = slow->next;
        }
        return res;
    }
};