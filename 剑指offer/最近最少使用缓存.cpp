#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    int value;
    node *pre;
    node *next;
    node() : key(0), value(0), pre(nullptr), next(nullptr) {}
    node(int k ,int v) : key(k), value(v), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int size = 0;
    int capacity = 0;
    node *head;
    node *tail;
    unordered_map<int, node *> cache;

public:
    LRUCache(int capacity): capacity(capacity) {
        head = new node(999, 999);
        tail = new node(-999, -999);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            node *target = cache[key];
            target->pre->next = target->next;
            target->next->pre = target->pre;
            moveToHead(target);
            return target->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            node *target = cache[key];
            target->value = value;
            target->pre->next = target->next;
            target->next->pre = target->pre;
            moveToHead(target);
        }
        else {
            if(size == capacity) {
                delTail();
                size--;
            }
            node *temp = new node(key, value);
            cache[key] = temp;
            size++;
            moveToHead(temp);
        }
    }
    void moveToHead(node* target) {
        target->next = head->next;
        target->next->pre = target;
        head->next = target;
        target->pre = head;
    }
    void delTail() {
        node *target = tail->pre;

        target->pre->next = target->next;
        target->next->pre = target->pre;
        cache.erase(target->key);
        delete target;
    }
};