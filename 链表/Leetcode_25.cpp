#include "iostream"
#include "vector"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (k == 1 || !head)
        return head;
    ListNode *NewHead = new ListNode(0);
    ListNode *temp_head = NewHead;
    while (head)
    {
        ListNode *end = head;
        int count = 0;
        while(end){
            count++;
            end = end->next;
        }
        end = head;
        if(count < k){
            temp_head->next = end;
            return NewHead->next;
        }
        for (int i = 0; i < k; i++)
        {
            if (!head)
                return NewHead->next;
            ListNode *N = head->next;
            head->next = temp_head->next;
            temp_head->next = head;
            head = N;
        }
        temp_head = end;
    }
    return NewHead->next;
}
