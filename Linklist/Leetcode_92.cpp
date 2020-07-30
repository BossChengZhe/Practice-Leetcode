#include "iostream"
#include "vector"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (m == n)
        return head;
    ListNode *res = new ListNode(INT_MAX);
    res->next = head;
    ListNode *left = NULL, *right = NULL;
    int cnt = 0;
    head = res;
    while (head)
    {
        if (cnt + 1 == m)
            left = head;
        head = head->next;
        cnt++;
        if (cnt == n)
        {
            right = head->next;
            break;
        }
    }
    head = left->next->next;
    left->next->next = right;
    while (head != right)
    {
        ListNode *temp = head->next;
        head->next = left->next;
        left->next = head;
        head = temp;
    }
    return res->next;
}