#include <bits/stdc++.h>
using namespace std;

class Solution2
{
public:
    string removeDuplicates(string S)
    {
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 1; i < S.size(); i++)
            {
                if (S[i] == S[i - 1])
                {
                    S.erase(S.begin() + i);
                    S.erase(S.begin() + i - 1);
                    flag = true;
                }
            }
        }
        return S;
    }
};
//  方法2：利用栈来解决

class Solution
{
public:
    string removeDuplicates(string S)
    {
        string res;
        for (auto a : S)
        {
            if (!res.empty() && res.back() == a)
                res.pop_back();
            else
                res.push_back(a);
        }
        return res;
    }
};