#include "iostream"
#include "string"
#include "vector"
#include "stack"
using namespace std;

int longestValidParentheses(string s)
{
    // 栈法解决最长有效括号的问题
    stack<int> temp;
    int res=0;
    temp.push(-1);
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i=='('])
            temp.push(i);
        else{
            temp.pop();
            if(temp.empty())
                temp.push(i);
            else
                res = (res >= i - temp.top()) ? res : i - temp.top();
        }
    }
    return res;
}