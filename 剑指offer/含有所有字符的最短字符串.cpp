#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        vector<int> cnt(26, 0);
        for (auto &i : t)
        {
            cnt[i - 'a']--;
        }
        int diff = 0;
        for (auto &i : cnt)
        {
            if(i)
                diff++;
        }

        int j = 0;
        while(cnt[j]==0)
            j++;
        
        vector<int> char_num(26, 0);
        string res = s;
        for (size_t i = 0; i < s.length(); i++)
        {
            int rank = s[i] - 'a';
            if(cnt[rank]){
                char_num[rank]++;
                 if(char_num[rank]==cnt[rank])
                diff--;
            
                if(diff==0) {
                    // 窗口左沿右移，右移到下一个出现在模式子串的字符上
                    res = res.length() > i - j + 1 ? s.substr(j, i - j + 1) : res;
                    char_num[s[j] - 'a']--;
                    while(!cnt[s[j]-'a'])
                        j++;
                    if(char_num[s[j]-'a'] >= cnt[s[j]-'a'])
                        res = s.substr(j, i - j + 1);
                    else
                        diff++;
                }
            }
        }
        return res;
    }
};