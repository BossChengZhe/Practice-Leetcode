#include "iostream"
#include "map"
#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

vector<int> findSubstring_S(string s, vector<string> &words)
{
    vector<int> res;
    if (!words.size())
        return {};
    // 统计words中单词出现的频率
    unordered_map<string, int> times;
    for (auto &str : words)
        times[str]++;
    unordered_map<string, int> cache;
    int unit_len = words[0].size(), length = words.size() * unit_len;
    for (int i = 0; i < s.size() - length + 1; i++)
    {
        for (int j = 0; j < words.size(); j++)
            // 统计当前窗口出现的单词频率
            cache[s.substr(i + j * unit_len, unit_len)]++;
        if (cache == times)
            res.push_back(i);
    }
    return res;
}

// 接下来是优化版本
vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> res;
    if (!words.size())
        return {};
    unordered_map<string, int> times;
    for (auto &s : words)
        times[s]++;
    unordered_map<string, int> cache;
    int unit_len = words[0].size(), all_len = unit_len * words.size();
    for (int i = 0; i < unit_len; i++)
    {
        int start = i;
        string temp = "";
        for (int j = i; j < s.size() - unit_len + 1 && start < s.size() - all_len + 1; j += unit_len)
        {
            temp = s.substr(j, unit_len);
            cache[temp]++;
            if (times.find(temp) == times.end())
            {
                cache.clear();
                start = j + unit_len;
            }
            else{
                if (cache[temp] > times[temp])
                {
                    int diff = cache[temp] - times[temp];
                    while (diff > 0 && start < s.size() - unit_len + 1)
                    {
                        string kl = s.substr(start, unit_len);
                        if ( kl== temp)
                            diff--;
                        if (cache.find(kl)!=cache.end()&&cache[kl]>0)
                            cache[kl]--;
                        start += unit_len;
                    }
                }
                if (times == cache)
                {
                    res.push_back(start);
                }
            }
        }
        cache.clear();
    }
    return res;
}

int main()
{
    vector<string> words = {"aa","aa","aa"};
    string s = "aaaaaaaa";
    findSubstring(s, words);
    return 0;
}