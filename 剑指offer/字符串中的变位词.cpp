#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        vector<int> char_nums(26, 0);
        for (size_t i = 0; i < s1.length(); i++)
        {
            char_nums[s1[i] - 'a']++;
            char_nums[s2[i] - 'a']--;
        }

        int diff = 0;
        for (auto &i : char_nums)
        {
            if(i)
                diff++;
        }

        if(diff ==0)
            return true;

        for (size_t i = s1.length(); i < s2.length(); i++)
        {
            char x = s2[i], y = s2[i - s1.length()];
            if(x==y)
                continue;
            
            if(char_nums[x -'a'] == 0)
                diff++;
            char_nums[x - 'a']--;
            if(char_nums[x -'a'] == 0)
                diff--;
            
            if(char_nums[y -'a'] == 0)
                diff++;
            char_nums[y - 'a']++;
            if(char_nums[y -'a'] == 0)
                diff--;
            if(!diff)
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.checkInclusion("adc", "dcda") << endl;
    return 0;
}
