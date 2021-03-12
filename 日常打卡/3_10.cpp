#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    stack<int> nums;
    stack<char> op;

    void cal()
    {
        if (nums.empty() || op.empty() || nums.size() < 2)
            return;
        int y = nums.top();
        nums.pop();
        int x = nums.top();
        nums.pop();
        nums.push(op.top() == '+' ? x + y : x - y);
        op.pop();
    }

public:
    int calculate(string s)
    {
        nums.push(0); // 避免第一个数字是复数
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == ')')
            {
                while (!op.empty())
                {
                    char oper = op.top();
                    if (oper != '(')
                        cal();
                    else
                    {
                        op.pop();
                        break;
                    }
                        
                }
            }
            else if (isdigit(s[i]))
            {
                int temp = 0;
                while (i < s.length() && isdigit(s[i]))
                {
                    temp = temp * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(temp);
                // cout << temp << endl;
                i--;
            }
            else
            {
                // 新操作入栈
                while (!op.empty() && op.top() != '(')
                    cal();
                op.push(s[i]);
            }
        }
        // cout << nums.size() << " " << op.size() << endl;
        while(!op.empty())
            cal();
        
        return nums.top();
    }
};