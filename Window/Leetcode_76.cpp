#include "algorithm"
#include "iostream"
#include "map"
#include "string"
#include "vector"
using namespace std;

string minWindow(string s, string t)
{
    
    map<char, int> cnt;
    string t1 = t;
    int kind_cnt = 0, min_sub = 0, len = INT_MAX;

    for (auto &z : t)
        cnt[z]++;
    
    int i = 0, j = 0;
    while (j < s.size())
    {
        if (cnt.find(s[j]) != cnt.end() && kind_cnt != cnt.size())
        {
            cnt[s[j]]--;
            kind_cnt += (cnt[s[j]] ? 0 : 1);
            if (kind_cnt == cnt.size())
            {
                while (i < j)
                {
                    if (cnt.find(s[i]) != cnt.end())
                    {
                        if(cnt[s[i]]==0)
                            break;
                        else if(cnt[s[i]]<0)
                            cnt[s[i]]++;
                    }
                    i++;
                }
                if (j - i + 1 < len)
                {
                    len = j - i + 1;
                    min_sub = i;
                }
                cnt[s[i]]++;
                kind_cnt--;
                i++;
            }
        }
        j++;
    }
    return len == INT_MAX ? "" : s.substr(min_sub, len);
}

int main()
{
    string x = "ADOBECODEBANC", z = "ABC";
    minWindow(x, z);
    return 0;
}