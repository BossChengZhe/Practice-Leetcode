#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

double myPow(double x, int n)
{
    if (x == 1.0 || x == 0)
        return x;
    if (n < 0)
        return 1.0 / myPow(x, -(n + 1)) / x;
    unsigned int temp_n = n;
    double pow_x = x;
    if (n % 2 == 0)
        x = 1;
    for (int i = 1; i < floor(log(temp_n) / log(2)) + 1; i++)
    {
        pow_x *= pow_x;
        unsigned int flag = (temp_n << (31 - i)) >> 31;
        if (flag)
            x *= pow_x;
    }
    return x;
}
