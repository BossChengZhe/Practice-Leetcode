#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<string> temp_strs(strs);
    vector<vector<string>> res;
    for(auto &i:strs)
        sort(i.begin(), i.end());
    unordered_map<string, vector<int>> times;
    for(int i = 0; i < strs.size(); i++)
        times[strs[i]].push_back(i);
    unordered_map<string, vector<int>>::iterator iter;
    for(auto iter = times.begin(); iter != times.end(); iter++)
    {
        vector<string> temp_res;
        for(int j = 0; j < iter->second.size(); j++)
        {
            string ss = temp_strs[iter->second[j]];
            temp_res.push_back(ss);
        }
        res.push_back(temp_res);
    }
    return res;
}
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
    return 0;
}