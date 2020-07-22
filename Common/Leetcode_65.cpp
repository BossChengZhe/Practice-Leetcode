#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

bool isNumber(string s)
{
    if (s.size() == 0 || (s.size() == 1 && !isdigit(s[0])))
        return false;
    vector<bool> flag(3, true);
    bool num_apper = false;
    int start = 0, end = s.size() - 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            start++;
        else
            break;
    }
    for (int i = end; i >= 0; i--)
    {
        if (isspace(s[i]))
            end--;
        else
            break;
    }
    s = s.substr(start, end - start + 1);
    if (s[0] == '+' || s[0] == '-')
        flag[0] = false;
    else if (isdigit(s[0]))
    {
        flag[0] = false;
        num_apper = true;
    }
    else if (s[0] == '.' && 0 != s.size() - 1 && isdigit(s[1]))
    {
        flag[0] = false;
        flag[1] = false;
    }
    else
        return false;
    for (int i = 1; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            num_apper = true;
        else if ((s[i] == '+' || s[i] == '-') && i != s.size() - 1 && isdigit(s[i + 1]) && flag[0])
            // 出现正负号，并且正负号后有数字继续
            flag[0] = false;
        else if (s[i] == '.' && flag[1])
        {
            flag[1] = false;
            flag[0] = false;
            cout << i << endl;
            if ((i != s.size() - 1 && (!isdigit(s[i - 1]) && !isdigit(s[i + 1]))) || (i == s.size() - 1 && !isdigit(s[i - 1])))
                return false;
        }
        else if (s[i] == 'e' && flag[2] && i != s.size() - 1 && num_apper)
        {
            flag[0] = true;
            flag[1] = false;
            flag[2] = false;
        }

        else
            return false;
    }
    return true;
}