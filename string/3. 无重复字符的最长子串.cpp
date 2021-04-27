#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> flag;
        int i = 0, j = 0;
        int res = 0;
        while (j < s.length())
        {
            auto iter = flag.find(s[j]);
            if (iter == flag.end())
            {
                res = max(res, j - i + 1);
                flag[s[j]] = j;
                j++;
            }
            else
            {
                int temp = i;
                i = iter->second + 1;
                while (temp < i)
                {
                    flag.erase(flag.find(s[temp]));
                }
            }
        }
        return res;
    }
};
// map存储比较暴力
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> ss;
        int i = 0, j = 0;
        int res = 0;
        while (j < s.length())
        {
            auto iter = ss.find(s[j]);
            if (iter == ss.end())
            {
                ss.insert(s[j]);
                res = max(res, j - i + 1);
                j++;
            }
            else{
                while(s[i]!=s[j])
                    ss.erase(s[i++]);
                i++;
                // cout << i << endl;
                j++;
            }
        }
        return res;
    }
};
// unordered_set时间和空间好一点