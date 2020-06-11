#include "iostream"
#include "stack"
#include "vector"
using namespace std;

vector<int> dailyTemperatures_s(vector<int> &T)
{
    // 暴力法
    vector<int> res(T.size());
    for (int i = 0; i < T.size(); i++)
    {
        for (int j = i + 1; j < T.size(); j++)
        {
            if (T[j] > T[i])
            {
                res[i] = j - i;
                break;
            }
        }
    }
    return res;
}
vector<int> dailyTemperatures(vector<int> &T)
{
    // 单调栈法
    vector<int> res(T.size());
    stack<int> temp_s;
    for (int i = 0; i < T.size(); i++)
    {
        if (temp_s.empty())
        {
            temp_s.push(i);
            continue;
        }
        while (!temp_s.empty() && T[temp_s.top()] < T[i])
        {
            res[temp_s.top()] = i - temp_s.top();
            temp_s.pop();
        }
        temp_s.push(i);
    }
    return res;
}