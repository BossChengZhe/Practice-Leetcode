#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        vector<int> cnt(60, 0);
        for (auto &i : t)
        {
            cnt[i - 'A']++;
        }
        int diff = 0;
        for (auto &i : cnt)
        {
            if(i)
                diff++;
        }
        int j = 0;
        while(j < s.length() && cnt[s[j]-'A']==0)
            j++;
        vector<int> char_num(60, 0);
        string res;
        for (size_t i = 0; i < s.length(); i++)
        {
            int rank = s[i] - 'A';
            if(cnt[rank]){
                char_num[rank]++;
                if(char_num[rank]==cnt[rank])
                    diff--;
            
                if(diff==0) {
                    res = res.length() > i - j + 1 || !res.length() ? s.substr(j, i - j + 1) : res;
                    while(true) {
                        char del_char = s[j];
                        int num = --char_num[s[j++] - 'A'];
                        while(j <= i && !cnt[s[j]-'A'] )
                            j++;
                        if(num >= cnt[del_char-'A']) 
                            res = res.length() > i - j + 1 || !res.length() ? s.substr(j, i - j + 1) : res;
                        else {
                            diff++;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.minWindow("abcabdebac", "cda") << endl;
    return 0;
}
