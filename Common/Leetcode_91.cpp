#include "iostream"
#include "string"
#include "vector"
using namespace std;

void curr(string s, int &res, int current)
{
    if(s[current]=='0')
        return;
    if (current == s.length())
    {
        res++;
        return;
    }
    curr(s, res, current + 1);
    if (s.size() >= current + 2)
    {
        int x = atoi(s.substr(current, 2).c_str());
        if (x < 27 && x > 0)
            curr(s, res, current + 2);
    }
}

int numDecodings(string s)
{
    if(s.size()==0)
        return 0;
    int res = 0;
    curr(s, res, 0);
    return res;
}

int main()
{
    int x = numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948");
    cout << x << endl;
    return 0;
}