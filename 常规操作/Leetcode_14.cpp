#include "iostream"
#include "string"
#include "vector"
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string s;
    if(!strs.size())
        return "";
    int min_size = INT_MAX;
    // 寻找最短字符串防止溢出
    for (int i = 0; i < strs.size(); i++)
        min_size = (min_size > strs[i].size()) ? strs[i].size() : min_size;
    for (int i = 0; i < min_size; i++)
    {
        char w = strs[0][i];
        for (int j = 0; j < strs.size(); j++)
        {
            if (w != strs[j][i])
                return s;
        }
        s += w;
    }
    return s;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    string s = longestCommonPrefix(strs);
    cout << s << endl;
    return 0;
}