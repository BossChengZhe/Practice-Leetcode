#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length())
            return 0;
        int i = 0, j = 0;
        unsigned int record = 0;
        int res = 0;
        while (j < s.length())
        {
            if (((1u << (s[j] - 'a')) & record) == 0u) {
                // 不存在重复字符，窗口右沿右移
                record |= (1u << (s[j] - 'a'));
                j++;
                res = max(res, j - i);
            }
            else {
                // 存在重复字符，将窗口左沿右移
                while(s[i]!=s[j] && i < j)
                {
                    record -= (1u << (s[i] - 'a'));
                    i++;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> usn;
        int j = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(usn.count(s[i]) == 0){
                usn.insert(s[i]);
                res = max(res, i - j + 1);
            }
            else {
                while(s[j] != s[i]) {
                    usn.erase(s[j++]);
                }
                j++;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    return 0;
}
