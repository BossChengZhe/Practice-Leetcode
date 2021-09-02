#include <bits/stdc++.h>
using namespace std;

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!(headA && headB))
            return nullptr;
        ListNode *A = headA, *B = headB;
        int null_times = 0;
        while(A != B) {
            A = A->next;
            if(A==nullptr) {
                null_times++;
                A = headB;
            }
            B = B->next;
            if(B==nullptr) {
                null_times++;
                B = headA;
            }
            if(null_times > 2)
                return nullptr;
        }
        return A == B ? A : nullptr;
    }
};