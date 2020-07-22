#include "iostream"
#include "map"
#include "queue"
#include "vector"
using namespace std;

vector<string> z = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> res;

void recurre(string digits, string s, int index)
{
    if (index == digits.size())
    {
        // 递归终止条件，当遍历到输入字符最后一个字符时
        res.push_back(s);
        return;
    }
    string temp = z[digits[index] - '0'];
    for (int i = 0; i < temp.size(); i++)
    {
        recurre(digits, s + temp[i], index + 1);
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
        return {};
    recurre(digits, {}, 0);
    return res;
}

vector<string> letterCombinations2(string digits)
// 思路2：电话号码组合符合先入先出的队列思想，可以用队列代替递归算法
{
    if (digits.size() == 0)
        return {};
    queue<string> Q;
    for (int i = 0; i < z[digits[0] - '0'].size(); i++)
    {
        string xxx;
        xxx += z[digits[0] - '0'][i];
        Q.push(xxx);
    }
    for (int i = 1; i < digits.size(); i++)
    {
        int Q_size = Q.size();
        string temp_string = z[digits[i] - '0'];
        for (int j = 0; j < Q_size; j++)
        {
            string fr = Q.front();
            Q.pop();
            for (int k = 0; k < temp_string.size(); k++)
            {
                Q.push(fr + temp_string[k]);
            }
        }
    }
    while (!Q.empty())
    {
        res.push_back(Q.front());
        Q.pop();
    }
    return res;
}
int main()
{

    return 0;
}