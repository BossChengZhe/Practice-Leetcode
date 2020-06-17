#include "iostream"
#include "string"
#include "vector"
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string temp("1"), res;
    char flag;
    for (int i = 1; i < n; i++)
    {
        res = "";
        flag = temp[0];
        int length = 1, k;
        for (k = 1; k < temp.size(); k++)
        {
            if (temp[k] == flag)
                length++;
            else
            {
                res += to_string(length);
                res += flag;
                length = 1;
                flag = temp[k];
            }
        }
        res += to_string(length);
        res += flag;
        temp = res;
    }
    return res;
}