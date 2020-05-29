#include "iostream"
#include "map"
#include "string"
#include "vector"
using namespace std;

int romanToInt(string s)
{
    map<string, int> str = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, 
        {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
    vector<string> temp = {"I", "V", "X", "L", "C", "D", "M", "IV", "IX", "XL", "XC", "CD", "CM"};
    int i = 0, res = 0;
    while(i < s.size())
    {
        switch(s[i]){
            case 'I':
                if(i < s.size() - 1 && s[i+1] == 'V')
                {
                    res += str["IV"];
                    i++;
                }
                else if(i < s.size() - 1 && s[i+1] == 'X')
                {
                    res += str["IX"];
                    i++;
                }
                else
                    res += str["I"];
                break;
            case 'X':
                if(i < s.size() - 1 && s[i+1] == 'L')
                {
                    res += str["XL"];
                    i++;
                }
                else if(i < s.size() - 1 && s[i+1] == 'C')
                {
                    res += str["XC"];
                    i++;
                }
                else
                    res += str["X"];
                break;
            case 'C':
                if(i < s.size() - 1 && s[i+1] == 'D')
                {
                    res += str["CD"];
                    i++;
                }
                else if(i < s.size() - 1 && s[i+1] == 'M')
                 {
                    res += str["CM"];
                    i++;
                }
                else
                    res += str["C"];
                break;
            case 'V':
                res += str["V"];
                break;
            case 'L':
                res += str["L"];
                break;
            case 'D':
                res += str["D"];
                break;
            case 'M':
                res += str["M"];
                break;
        }
        i++;
    }
    return res;
}

int main()
{
    int res = romanToInt("MCMXCIV");
    cout << res << endl;
    return 0;
}