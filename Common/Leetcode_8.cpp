#include "iostream"
#include "string"
#include "vector"
#include <algorithm>
using namespace std;

/*************************************************************************************************************
边界问题的思考
1. 当第一个字符是除开'+','-','0-9',' '之外的所有字符统统判零
2. 第一个'+'(或者'-')后接着出现+-，判零
3. 在res*10+pop的过程中，随时检验是否越界
*************************************************************************************************************/

int myAtoi(string str)
{
    if (str[0] == ' ' || (str[0] >= '0' && str[0] <= '9') || str[0] == '-' || str[0] == '+')
    {
        int flag = 1, res = 0, i = 0;

        while (str[i] == ' ')
            i++;

        if (str[i] == '-')
        {
            i++;
            flag = -1;
        }
        else if (str[i] == '+')
            i++;
        if (i == str.size())
            return 0;
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 0;
        res = (str[i++] - '0') * flag;
        while (str[i] >= '0' && str[i] <= '9' && i < str.size())
        {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') * flag > 7))
                return INT_MAX;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && (str[i] - '0') * flag < INT_MIN % 10))
                return INT_MIN;
            res *= 10;
            res += (str[i++] - '0') * flag;
        }
        return res;
    }
    else
        return 0;
}

int main()
{
    string s = "2147483646";
    int res = myAtoi(s);
    cout << res << endl;

    return 0;
}