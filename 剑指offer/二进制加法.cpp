#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        string res;
        int temp = 0;
        while(i >= 0 && j>=0) {
            int e = a[i--] - '0' + b[j--] - '0';
            char cur = (e + temp) % 2 + '0';
            res.push_back(cur);
            temp = (e + temp) / 2;
        }
        while(i>=0) {
            int e = a[i--] - '0';
            char cur = (e + temp) % 2 + '0';
            res.push_back(cur);
            temp = (e + temp) / 2;
        }
        while(j>=0) {
            int e = b[j--] - '0';
            char cur = (e + temp) % 2 + '0';
            res.push_back(cur);
            temp = (e + temp) / 2;
        }
        if(temp)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};