#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<bool> visit, map<string, int> &res, string temp_res, string s)
    {
        if (temp_res.size() == s.length())
        {
            res[temp_res]++;
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (visit[i])
                continue;
            visit[i] = true;
            dfs(visit, res, temp_res + s[i], s);
            visit[i] = false;
        }
    }
    vector<string> permutation(string s)
    {
        map<string, int> tres;
        vector<bool> visit(s.length(), false);
        dfs(visit, tres, "", s);
        vector<string> res;
        for (auto iter = tres.begin(); iter != tres.end(); iter++)
        {
            res.push_back(iter->first);
        }
        return res;
    }
};

// 上面的使用的方法就是属于暴利去重的一类，实际上我们拥有更加机智的选择

class Solution2
{
public:
    void dfs(vector<bool> visit, vector<string> &res, string temp_res, string s)
    {
        if(temp_res.length()==s.length())
        {
            res.push_back(temp_res);
            return;
        }
        for(int i = 0; i < s.length(); i++)
        {
            int low = lower_bound(s.begin(), s.end(), s[i])-s.begin();
            bool flag = visit[low];
            for(int j = low+1; j < i; j++)
                flag = flag && visit[j];
            if (visit[i] || (i > low && flag))
                continue;
            // if (visit[i])
            //     continue;
            visit[i] = true;
            dfs(visit, res, temp_res + s[i], s);
            visit[i] = false;
        }
    }
    vector<string> permutation(string s)
    {
        sort(s.begin(), s.end());
        vector<string> res;
        vector<bool> visit(s.length(), false);
        dfs(visit, res, "", s);
        return res;
    }
};
