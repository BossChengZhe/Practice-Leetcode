#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    int step = 2 * numRows - 2;
    int index = 0, gap = 0;
    int len = s.size();
    string res;
    for (int i = 0; i < numRows; i++)
    {
        index = i;
        gap = 2 * i;
        while (index < len)
        {
            res += s[index];
            gap = step - gap;
            index += (i == 0 || i == numRows-1) ? step : gap;
        }
    }
    return res;
}

int main()
{
    string s = "LEETCODEISHIRING";
    int numRows = 4;
    string res = convert(s, numRows);
    cout << res << endl;
    return 0;
}