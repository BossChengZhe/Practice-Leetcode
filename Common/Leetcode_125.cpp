#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool isPalindrome(string s)
{
    int front = 0, end = s.size();
    bool res = true;
    while (front < end)
    {
        while (!isalnum(s[front]) && front < s.size())
            front++;
        while (!isalnum(s[end]) && end > 0)
            end--;
        if (front >= end)
            break;
        if (tolower(s[front]) != tolower(s[end]))
        {
            res = false;
            break;
        }
        front++;
        end--;
    }
    return res;
}