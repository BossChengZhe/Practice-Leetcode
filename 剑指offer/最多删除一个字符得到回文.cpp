#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if(s.length()<2)
            return true;
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i]==s[j]) {
                i++;
                j--;
                continue;
            }
            else {
                return check(s.substr(i + 1, j - i)) || check(s.substr(i, j - i));
            }
        }
        return true;
    }
    bool check(string s ) {
        if(s.length()<2)
            return true;
        int i = 0, j = s.length() - 1;
        while(i < j)
            if(s[j--]!=s[i++])
                return false;
        return true;
    }
};