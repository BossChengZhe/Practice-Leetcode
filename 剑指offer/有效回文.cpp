#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.length())
            return true;
        string ss;
        for (auto &i : s) {
            if(isdigit(i))
                ss += i;
            if(isalpha(i))
                ss += tolower(i);
        }
            

        int i = 0, j = ss.length() - 1;
        while(i<j) {
            if(ss[i++] != ss[j--])
                return false;
        }
        return true;
    }
};