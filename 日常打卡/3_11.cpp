#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> nums;
        int len = s.length();
        int num = 0;
        char pre_operation = '+';
        for (int i = 0; i < len; i++)
        {
            // cout << i << endl;
            if (s[i] == ' ')
                continue;
            if (isdigit(s[i]))
            {
                num = num * 10 + s[i] - '0';
                cout << num << endl;
            }
            if (i == len - 1 || !isdigit(s[i]) && s[i] != ' ')
            {
                if (pre_operation == '+')
                    nums.push(num);
                else if (pre_operation == '-')
                    nums.push(-num);
                else if (pre_operation == '*')
                {
                    int temp = nums.top();
                    nums.pop();
                    nums.push(temp * num);
                }
                else
                {
                    int temp = nums.top();
                    nums.pop();
                    nums.push(temp / num);
                }
                pre_operation = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }
        cout << res << endl;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    Solution a;
    a.calculate(s);
    return 0;
}
