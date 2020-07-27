#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool isSubsequence(string s, string t)
{
    int n = s.size(), m = t.size();
    int i = 0;
    for(int j = 0; j < n; j++)
    {
        if(s[j]==t[i])
            i++;
    }
    return i == m;
}