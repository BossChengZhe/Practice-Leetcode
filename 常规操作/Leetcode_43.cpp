#include "iostream"
#include "string"
#include "vector"
using namespace std;

string pls(string num1, string num2)
{
    string res;
    int temp = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    while (i >= 0 && j >= 0)
    {
        temp += ((num1[i] - '0') + (num2[j] - '0'));
        res.insert(0, to_string(temp % 10));
        temp /= 10;
        i--;
        j--;
    }
    while (i >= 0)
    {
        temp += (num1[i] - '0');
        res.insert(0, to_string(temp % 10));
        temp /= 10;
        i--;
    }
    while (j >= 0)
    {
        temp += (num2[j] - '0');
        res.insert(0, to_string(temp % 10));
        temp /= 10;
        j--;
    }
    if (temp)
        res.insert(0, to_string(temp));
    return res;
}
string multiply(string num1, string num2)
{
    if(num1=="0"||num2=="0")
        return "0";
    string res;
    int temp = 0;
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        string temp_res;
        temp = 0;
        for (int j = num2.size() - 1; j >= 0; j--)
        {
            temp += ((num1[i] - '0') * (num2[j] - '0'));
            temp_res.insert(0, to_string(temp % 10));
            temp /= 10;
        }
        if (temp)
            temp_res.insert(0, to_string(temp));
        for (int j = 0; j < (num1.size() - i - 1); j++)
            temp_res += '0';
        res = pls(res, temp_res);
    }
    return res;
}