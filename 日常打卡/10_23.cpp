#include "iostream"
#include "vector"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head)
{
    int length = 0;
    ListNode *temp = head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    if (length < 2)
        return true;
    temp = new ListNode(-10);
    temp->next = head;
    head = head->next;
    temp->next->next = NULL;
    for (int i = 1; i < length / 2; i++)
    {
        ListNode *q = head->next;
        head->next = temp->next;
        temp->next = head;
        head = q;
    }
    if (length % 2)
        head = head->next;
    ListNode *ptr1 = temp->next, *ptr2 = head;
    for (int i = 0; i < length / 2; i++)
    {
        if (ptr1->val != ptr2->val)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}