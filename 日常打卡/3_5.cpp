#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    stack<int> s1, s2;
    void output()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    /** Initialize your data structure here. */

    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if(s2.empty())
            output();
        int i = s2.top();
        s2.pop();
        return i;
    }

    /** Get the front element. */
    int peek()
    {
        if(s2.empty())
            output();
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

// 每一次都要倒腾，压入时可以节省，当输出栈为空时，将输入栈所有元素压入输出栈