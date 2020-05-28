#include "iostream"
#include "vector"
using namespace std;

int reverse(int x)
{
    // 边界问题的处理
    int res = 0;
    while (x != 0)
    {
        if(res > INT_MAX/10 || (res == INT_MAX/10 && x % 10 > 7)) return 0;
        if(res < INT_MIN/10 || (res == INT_MIN/10 && x % 10< INT_MIN%10))
            return 0;
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    int x = -2147483648;
    int res = reverse(x);
    cout << res << endl;
    return 0;
}