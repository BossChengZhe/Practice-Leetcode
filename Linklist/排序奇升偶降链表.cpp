#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void sort(ListNode *head)
    {
        // 拆分列表
        if (!head)
            return;
        auto evenhead = head->next;
        // prin(head);
        ListNode *odd = head, *even = evenhead;
        while (even && even->next)
        {
            printf("%d %d\n", odd->val, even->val);
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = nullptr;

        evenhead = reverseList(evenhead);

        // 合并有序链表
        ListNode *head1 = new ListNode(INT_MAX);
        odd = head1;
        while (head && evenhead)
        {
            if (head->val < evenhead->val)
            {
                odd->next = head;
                head = head->next;
            }
            else
            {
                odd->next = evenhead;
                evenhead = evenhead->next;
            }
            odd = odd->next;
        }
        if (head)
            odd->next = head;
        if (evenhead)
            odd->next = evenhead;

        odd = head1;
        head1 = head1->next;
        delete odd;
        prin(head1);

        // even = head1;
        // prin(head1);
        return;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *q = head->next;
        head->next = nullptr;
        while (q)
        {
            ListNode *temp = q->next;
            q->next = head;
            head = q;
            q = temp;
        }
        return head;
    }
    void prin(ListNode *head)
    {
        ListNode *p = head;
        while (p)
        {
            cout << p->val << endl;
            p = p->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    ListNode *q = head;
    vector<int> nums = {1, 100, 9, 70, 20, 40, 50, 10, 90, 8};
    for (int i = 0; i < nums.size(); i++)
    {
        q->next = new ListNode(nums[i]);
        q = q->next;
    }
    q = head;
    head = head->next;
    delete q;
    Solution test;
    test.sort(head);
    return 0;
}
