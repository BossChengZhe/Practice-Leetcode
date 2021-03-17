#include <bits/stdc++.h>
using namespace std;

struct KeyValue
{
    int key;
    int value;
    KeyValue *next;
    KeyValue(int a, int b) : key(a), value(b), next(nullptr) {}
};

class MyHashMap1
{
private:
    vector<KeyValue *> node;
    int base;

public:
    /** Initialize your data structure here. */
    MyHashMap1()
    {
        base = 10000;
        node = vector<KeyValue *>(base, nullptr);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int hash = key % base;
        if (!node[hash])
        {
            // 创建头结点，好办事儿
            node[hash] = new KeyValue(INT_MAX, INT_MAX);
            node[hash]->next = new KeyValue(key, value);
        }
        else
        {
            KeyValue *pre = node[hash];
            KeyValue *temp = pre->next;
            while (temp)
            {
                while (temp)
                {
                    if (temp->value == key)
                    {
                        temp->value = value;
                        return;
                    }
                    pre = temp;
                    temp = temp->next;
                }
                pre = new KeyValue(key, value);
            }
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        KeyValue *temp = node[key % base];
        while (temp)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        KeyValue *temp = node[key % base];
        if (!temp)
        {
            // 说明压根儿没这个key
            return;
        }
        else
        {
            while (temp->next)
            {
                if (temp->next->key == key)
                {
                    KeyValue *p = temp->next;
                    temp->next = p->next;
                    delete p;
                    return;
                }
            }
        }
    }
    void prind(int key)
    {
        KeyValue *temp = node[key % base];
        while (temp->next)
        {
            cout << temp->next->value << endl;
            temp = temp->next;
        }
    }
};
// 上面那种只供学习，我也不知道哪里有bug

class MyHashMap
{
    vector<list<pair<int, int>>> node;
    const int base =1000;

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        node = vector<list<pair<int, int>>>(base, list<pair<int, int>>(base));
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int hash = key % base;
        for (auto i = node[hash].begin(); i != node[hash].end(); i++)
            if (i->first == key)
            {
                i->second = value;
                return;
            }
        node[hash].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int hash = key % base;
        for (auto i = node[hash].begin(); i != node[hash].end(); i++)
            if (i->first == key)
            {
                return i->second ;
            }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int hash = key % base;
        for (auto i = node[hash].begin(); i != node[hash].end(); i++)
            if (i->first == key)
            {
                node[hash].erase(i);
                return;
            }
    }
};
