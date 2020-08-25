#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool repeatedSubstringPattern1(string s)
{
    int len = s.length();
    for (int i = 1; i <= len / 2; i++)
    {
        int flag = true;
        string temp = s.substr(0, i);
        if (len % i == 0)
        {
            for (int j = i; j < len; j += i)
            {
                if (temp != s.substr(j, i))
                    flag = false;
            }
            if (flag)
                return true;
        }
    }
    return false;
}


bool repeatedSubstringPattern(string s)
{
    return (s + s).find(s, 1) != s.size();
}