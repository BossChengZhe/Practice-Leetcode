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

ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    if (!l1 && !l2)
        return NULL;

    ListNode *Head = new ListNode(-1);
    ListNode *temp = Head;
    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            Head->next = l2;
            
            l2 = l2->next;
        }
        else
        {
            Head->next = l1;
            l1 = l1->next;
        }
        Head = Head->next;
    }
    Head->next = (l1) ? l1 : l2;
    Head = temp->next;
    delete temp;
    return Head;
}

ListNode *cur(vector<ListNode *> &lists, int start, int end)
{
    if(start < end-1)
    {
        int mid = (start + end) / 2;
        ListNode *L1 = cur(lists, start, mid);
        ListNode *L2 = cur(lists, mid + 1, end);
        return mergeList(L1, L2);
    }
    else if(start == end-1)
        return mergeList(lists[start], lists[end]);
    else
        return lists[start];
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    // 分治策略，将K个有序链表分治合并
    if(lists.size()==0)
        return NULL;
    return cur(lists, 0, lists.size() - 1);
}
  
int main()
{

    return 0;
}