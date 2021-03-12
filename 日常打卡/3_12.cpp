#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int cnt = 0;
        for(int i = 0; i < preorder.size(); i++)
        {
            if(cnt==0)
                return false;
            else if(preorder[i]=='#')
                cnt--;
            else
                cnt++;
        }
        return cnt == 0;
    }
};