#include "iostream"
#include "string"
#include "vector"
using namespace std;

string addStrings(string num1, string num2)
{
    string res;
    int carry = 0;
    int len1 = num1.size() - 1, len2 = num2.size() - 1;
    while (len1 >= 0 || len2 >= 0)
    {
        int temp;
        if (len1 >= 0 && len2 >= 0)
        {
            temp = num1[len1] - '0' + num2[len2] - '0';
            len1--;
            len2--;
        }

        else if (len1 >= 0 && len2 < 0)
        {
            temp = num1[len1] - '0';
            len1--;
        }
        else
        {
            temp = num2[len2] - '0';
            len2--;
        }
        char x = (temp + carry) % 10 + '0';
        res = x + res;
        carry = (temp + carry) / 10;
    }
    char x = carry + '0';
    return x == '0' ? res : x + res;
}