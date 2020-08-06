#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool judge(string &s1, string &s2)
{
    string s3 = s1 + s2;
    int left = 0, right = s3.length() - 1;
    while(left < right)
    {
        if(s3[left]!=s3[right])
            return false;
        left++;
        right--;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string> &words)
{
    vector<vector<int>> res;
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(judge(words[i], words[j]))
                res.push_back({i, j});
        }
    }
    return res;
}