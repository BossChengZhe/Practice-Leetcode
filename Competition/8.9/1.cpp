#include "iostream"
#include "string"
#include "vector"
using namespace std;

string makeGood(string s)
{
    int flag = true;
    while (flag)
    {
        flag = false;
        int len = s.length();
        string temp;
        for (int i = 0; i < len; i++)
        {
            if (i < len - 1&&((islower(s[i]) && s[i + 1] == toupper(s[i]))|| (isupper(s[i]) && s[i + 1] == tolower(s[i]))))
            {
                flag = true;
                i++;
                continue;
            }
            temp += s[i];
        }
        s = temp;
    }
    return s;
}

int main()
{
    string s = makeGood("leEeetcode");
    cout << s << endl;
    return 0;
}