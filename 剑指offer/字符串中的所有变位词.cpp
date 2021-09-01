#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length())
            return {};
        vector<int> char_num(26, 0);
        for (size_t i = 0; i < p.length(); i++)
        {
            char_num[p[i]-'a']--;
            char_num[s[i]-'a']++;
        }
        int diff = 0;
        for (auto &i : char_num)
        {
            if(i)
                diff++;
        }
        vector<int> res;
        if(!diff)
            res.push_back(0);
        for (size_t i = p.length(); i < s.length(); i++)
        {
            char x = s[i], y = s[i - p.length()];
            int rank_x = x - 'a', rank_y = y - 'a';

            if(char_num[rank_x] == 0)
                diff++;
            char_num[rank_x]++;
            if(char_num[rank_x] == 0)
                diff--;

            if(char_num[rank_y] == 0)
                diff++;
            char_num[rank_y]++;
            if(char_num[rank_y] == 0)
                diff--;
            if(diff == 0)
                res.push_back(i);
        }
        return res;
    }
};