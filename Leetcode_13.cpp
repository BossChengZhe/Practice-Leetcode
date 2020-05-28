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
    
}

int main()
{

    return 0;
}