#include "iostream"
#include "string"
#include "vector"
using namespace std;

int lengthOfLastWord(string s)
{
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isalpha(s[i]))
        {
            while (i >= 0 && isalpha(s[i]))
            {
                res++;
                i--;
            }
        }
        break;
    }
    return res;
}

int main()
{
    int res = lengthOfLastWord("a");
    cout << res << endl;
    return 0;
}