#include "iostream"
#include "string"
#include "vector"
using namespace std;

void curr(string s, vector<string> &res, string temp, int current, int cnt)
{
    if (current == s.length() && cnt == 4)
    {
        temp.pop_back();
        res.push_back(temp);
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (current + i <= s.length())
        {
            int x = stoi(s.substr(current, i).c_str());
            if ((x == 0 && i == 1) || (x <= 255 && s[current] != '0'))
                curr(s, res, temp + s.substr(current, i) + '.', current + i, cnt + 1);
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    string temp;
    curr(s, res, temp, 0, 0);
    return res;
}

int main()
{
    vector<string> res = restoreIpAddresses("010010");
    for (auto i : res)
        cout << i << endl;
    return 0;
}