#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string precess(const string &s) {
        string temp;
        temp += '^';
        for (auto &i : s)
        {
            temp += "#";
            temp += i;
        }
        temp += "#$";
        return temp;
    }
    int countSubstrings(string s) {
        string s1 = precess(s);
        vector<int> len(s1.length(), 0);
        int C = 0, R = 0, res = 0;
        cout << s1 << endl;
        for (int i = 1; i < s1.length(); i++)
        {
            if(R > i)
                len[i] = min(R - i, len[2 * C - i]);
            else
                len[i] = 1;
            while(s1[i-len[i]] == s1[i+len[i]])
                len[i]++;
            
            if(len[i]+i > R) {
                R = len[i] + i;
                C = i;
            }
            res += ((len[i] - 1) / 2 + (len[i] - 1) % 2);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.countSubstrings("aaa") << endl;
    return 0;
}
