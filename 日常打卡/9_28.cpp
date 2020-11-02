#include "iostream"
#include "queue"
#include "vector"
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
};

Node* connect2(Node* root) 
{
    if(!root)
        return root;
    Node* temp = root;
    queue<Node*> q;
    q.push(temp);
    while(!q.empty())
    {
        int q_size = q.size();
        Node* pre = 0;
        for(int i = 0; i < q_size; i++)
        {
            Node* tmp = q.front();
            q.pop();
            if(i==0){
                pre = tmp;
            }
            else{
                pre->next = tmp;
                pre = tmp;
            }

            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
    }
    return root;
}

void handle(Node* &last, Node* &p, Node* &nextStart) {
    if (last) {
        last->next = p;
    } 
    if (!nextStart) {
        nextStart = p;
    }
    last = p;
}

Node* connect(Node* root)
{
    if(!root)
        return NULL;
    Node *start =  root;
    while(start)
    {
        Node *newstart = 0, *last = 0;
        for(Node *i = start; i!=NULL; i=i->next)
        {
            if(i->left)
                handle(last, i->left, newstart);
            if(i->right)
                handle(last, i->right, newstart);
        }
        start = newstart;
    }
    return root;
}