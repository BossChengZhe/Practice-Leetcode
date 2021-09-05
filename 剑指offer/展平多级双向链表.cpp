#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int val, Node *p, Node *n, Node *c) : val(val), prev(p), next(n), child(c){}
    Node(int val) : val(val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {

private:
    Node* dfs(Node *head)
    {
        Node *pre = head;
        while(head) {
            Node *next_node = head->next;
            if(head->child) {
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                Node *temp = dfs(head->next);
                temp->next = next_node;
                if(next_node)
                    next_node->prev = temp;
            }
            pre= head;
            head = next_node;
        }
        cout << "return: " << pre->val << endl;
        return pre;
    }

public:
    Node* flatten(Node* head) {
        stack<Node *> s;
        if(head == nullptr)
            return head;
        dfs(head);
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Node *head1 = new Node(1);
    Node *head2 = new Node(2);
    Node *head3 = new Node(3);
    head1->child = head2;
    head2->child = head3;
    Solution S;
    S.flatten(head1);

    return 0;
}
