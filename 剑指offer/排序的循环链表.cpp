#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *temp = new Node(insertVal);
        if(head == nullptr)
        {
            temp->next = temp;
            return temp;
        }
        Node *i = head;
        Node *large = head, *small = head;
        do{
            if(insertVal >= i->val && insertVal <= i->next->val) {
                temp->next = i->next;
                i->next = temp;
                return head;
            }
            if(i->val >= large->val)
                large = i;
            if(i->next->val <= small->next->val) {
                small = i;
            }
            i = i->next;
        }while(i!=head);
        // 剩余没有插入只可能是插入的是比现有值要大或者要小的数
        if(temp->val >= large->val) {
            temp->next = large->next;
            large->next = temp;
            return head;
        }
        if(temp->val <= small->val) {
            temp->next = small->next;
            small->next = temp;
        }
        return head;
    }
};