#include <bits/stdc++.h>
using namespace std;

class CQueue {
private:
    stack<int> in, out;
    void output()
    {
        if(out.empty())
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
    }
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if(in.empty()&& out.empty())
            return -1;
        output();
        int i = out.top();
        out.pop();
        return i;
    }
};