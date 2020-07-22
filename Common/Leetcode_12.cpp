#include "iostream"
#include "map"
#include "string"
#include "vector"
using namespace std;

string intToRoman(int num)
{
    map<int, string> str = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};

    vector<int> z = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    string res;
    while (num > 0)
    {
        for (int i = z.size() - 1; i > -1; i--)
        {
            if (num >= z[i])
            {
                res += str[z[i]];
                num -= z[i];
                break;
            }
        }
    }
    return res;
}

int main()
{
    string res = intToRoman(58);
    cout << res << endl;
    return 0;
}