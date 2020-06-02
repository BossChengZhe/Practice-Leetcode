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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1 && !l2)
        return NULL;
    else if (!l1)
        return l2;
    else if (!l2)
        return l1;

    ListNode *Head = new ListNode(0);
    ListNode *temp = Head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            Head->next = l1;
            l1 = l1->next;
        }
        else
        {
            Head->next = l2;
            l2 = l2->next;
        }
        Head = Head->next;
    }

    Head->next = (l1) ? l1 : l2;
    Head = temp->next;
    delete temp;
    return Head;
}

int main()
{

    return 0;
}