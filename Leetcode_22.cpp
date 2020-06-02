#include "iostream"
#include "string"
#include "vector"
using namespace std;

void cur(vector<string> &res, string &current, int left, int right, int n)
{
    if (current.size() == 2 * n)
    {
        // 如果字符串的长度等于2*n说明当前组合已完成，可以添加入结果中,递归结束
        res.push_back(current);
        return;
    }
    if (left < n)
    {
        // 由于左括号的放置是没有限制的，探索在任意位置放置'('的结果
        current.push_back('(');
        cur(res, current, left + 1, right, n);
        current.pop_back(); // 消除当前层对current字符串的影响
    }
    if (right < left)
    {
        // 观察有效队列发现在所有')'之前，数量都是小于等于'('的数量的
        current.push_back(')');
        cur(res, current, left, right + 1, n);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string current;
    cur(res, current, 0, 0, n);
    return res;
}

vector<string> generateParenthesis_dp(int n)
{
    if(!n)
        return {};
    if(n==1)
        return {"()"};

    vector<vector<string>> dp(n + 1);
    dp[0] = {""};
    dp[1] = {"()"};
    for(int i = 2; i <=n ; i++)
    {
        for(int j = 0; j < i ; j++)
        {
            for(string q:dp[j]){
                for(string p:dp[i-j-1]){
                    string temp = "(" + q + ")" + p;
                    dp[i].push_back(temp);
                }
            }
        }
    }
    return dp[n];
}

int main()
{

    return 0;
}