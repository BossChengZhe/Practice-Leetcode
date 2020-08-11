#include "cmath"
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int countBinarySubstrings1(string s)
{
    int len = s.length();
    if (len == 0 || len == 1 || len == 2 && s[0] == s[1])
        return 0;
    if (len == 2 && s[0] != s[1])
        return 1;
    int pre = 1, next = 1;
    int res = 0;
    int i = 0;
    for (i = 1; i < len; i++)
    {
        if (s[i] != s[i - 1])
            break;
        pre++;
    }
    if (pre == len)
        return 0;
    for (i = i + 1; i < len; i++)
    {
        if (s[i] != s[i - 1])
        {
            res += min(pre, next);
            pre = next;
            next = 0;
        }
        next++;
    }
    res += min(pre, next);
    return res;
}

int countBinarySubstrings(string s)
{
    int res = 0, last = 0, ptr = 0;
    int len = s.length();
    while (ptr < len)
    {
        int cnt = 0;
        char c = s[ptr];
        while(ptr<len&&s[ptr]==c)
        {
            ++ptr;
            cnt++;
        }
        res += min(cnt, last);
        last = cnt;
    }
    return res;
}