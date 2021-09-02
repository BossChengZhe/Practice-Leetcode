#include <bits/stdc++.h>
using namespace std;

class qu{
private:
    vector<int> q;
    int size;
    int capacity;    // 实际容量
    int front;

public:
    qu(int ca) : capacity(ca), size(0), front(0) { q.resize(capacity, 0); }
    void push(int value) {
        if(size == capacity) 
        {
            cout << "error" << endl;
            return;
        }
        q[(front + size) % capacity] = value;
        size++;
    }
    int pop() {
        if(size == 0) {
            return -1;
        }
        int temp = front;
        front = (front + 1) % capacity;
        return q[temp];
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;


    return 0;
}
