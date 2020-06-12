#include "iostream"
#include "vector"
using namespace std;

int strStr(string haystack, string needle)
{
    if (needle.size() > haystack.size())
        return -1;
    if (!haystack.size() || !needle.size())
        return 0;
    for (int i = 0; i < haystack.size(); i++)
    {
        bool flag = true;
        int temp = i;
        for (int j = 0; j < needle.size()&&temp<haystack.size(); j++,temp++)
        {
            if (haystack[temp] != needle[j])
            {
                flag = false;
                break;
            }
            
        }
        if (flag)
            return i;
    }
    return -1;
}

int main()
{
    int x = strStr("mississippi", "issip");
    cout << x << endl;
    return 0;
}