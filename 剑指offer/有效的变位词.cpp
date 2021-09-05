#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26, 0);
        for (auto &i : s)
            hash[i - 'a']++;
        int diff = 0;
        for (auto &i : hash)
            if(i)
                diff++;
        
        for (auto &i : t)
        {
            int rank = --hash[i-'a'];
            if(rank < 0)
                return false;
            else if(rank == 0)
                diff--;
        }
        return diff == 0;
    }
};