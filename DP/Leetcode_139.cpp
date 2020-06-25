#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool inDic(vector<string> wordDict, string s)
{
    int low = 0, high = wordDict.size() - 1, mid = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(wordDict[mid]==s)
            return true;
        else if(wordDict[mid]>s)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    sort(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size()+1);
    dp[0] = true;
    int max_size = wordDict[0].size(), min_size = wordDict[0].size();

    for(int i = 0; i < wordDict.size(); i++)
    {
        max_size = (max_size>=wordDict[i].size())?max_size:wordDict[i].size();
        min_size=(min_size<=wordDict[i].size())?min_size:wordDict[i].size();
    }

    for(int i = 0; i < s.size(); i++)
    {
        int start = (i - max_size + 1 > 0) ? i - max_size + 1 : 0;
        int end = (i - min_size + 1 > 0) ? i - min_size + 1 : 0;
        for(int j = start; j < end+1; j++)
        {
            dp[i+1] = inDic(wordDict, s.substr(j, i - j + 1)) && dp[j];
            if(dp[i+1])
                break;
        }
    }
    return dp[s.size()-1];
}

int main()
{
    vector<string> wordDict = {"leet", "code"};
    wordBreak("leetcode", wordDict);
    return 0;
}