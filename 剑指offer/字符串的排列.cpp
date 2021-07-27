#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    int res_len;
    vector<string> permutation(string s) {
        res_len = s.length();
        vector<bool> visit(res_len, false);
        sort(s.begin(), s.end());
        dfs("", visit, s);
        return res;
    }

    void dfs(string tempres, vector<bool> visit, const string &ss) {
        if(tempres.length() == res_len) {
            res.push_back(tempres);
        }
        
        for (size_t i = 0; i < res_len; i++)
        {
            if(i>0 && !visit[i-1] && ss[i] == ss[i-1])             // 剔除了不相同的部分
                continue;
            if(!visit[i]) {
                visit[i] = true;
                tempres.push_back(ss[i]);
                dfs(tempres, visit, ss);
                tempres.pop_back();
                visit[i] = false;
            }
        }
    } 
};