#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int cnt = 0;
        int num = 0;
        for(int i = 0; i < preorder.size(); i++)
        {
            if(preorder[i]=='#')
                num = -1;
            else if(preorder[i]==',')
            {
                cnt+=num;
                if(cnt<0&&i!=preorder.size()-1)
                    return false;
            }
            else
                num = 1;
        }
        return cnt+num == -1;
    }
};