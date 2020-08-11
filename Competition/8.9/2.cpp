#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
using namespace std;

string reverse_invert(string s)
{
    for (int i = 0; i < s.length(); i++)
        s[i] = s[i] == '0' ? '1' : '0';
    reverse(s.begin(), s.end());
    return s;
}

char findKthBit(int n, int k)
{
    string s = "0";
    for (int i = 1; i < n; i++)
        s = s + '1' + reverse_invert(s);
    return s[k];
}