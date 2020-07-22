#include "iostream"
#include "vector"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *copy_head = head;
    int size = 0;
    while (copy_head)
    {
        size++;
        copy_head = copy_head->next;
    }
    ListNode *New_head = new ListNode(-1);
    New_head->next = head;
    head = New_head;
    for (int i = 0; i < size - n; i++)
        head = head->next;
    ListNode *temp = head->next;
    head->next = temp->next;
    delete temp;
    head = New_head->next;
    delete New_head;
    return head;
}
ListNode *removeNthFromEnd2(ListNode *head, int n)
// 一次遍历顶呱呱
{
    ListNode *copy_head = head;
    ListNode *New_head = new ListNode(-1);
    New_head->next = copy_head;
    ListNode *p = New_head;
    ListNode *q = New_head;
    for(int i = 0; i < n; i++)
        p = p->next;
    while(p->next != NULL){
        p = p->next;
        q = q->next;
    }
    copy_head = q->next;
    q->next = copy_head->next;
    delete copy_head;
    head = New_head->next;
    delete New_head;
    return head;
}
int main()
{

    return 0;
}