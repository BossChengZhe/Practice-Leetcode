#include "iostream"
#include "vector"
using namespace std;

bool isPalindrome(int x)
{
    int flag = x;
    if (x < 0)
        return false;
    int temp = 0;
    while (x != 0)
    {
        if (temp > INT_MAX / 10 || (temp == INT_MAX / 10 && x % 10 > INT_MAX % 10))
            return false;
        temp *= 10;
        temp += x % 10;
        x /= 10;
    }
    if (temp == flag)
        return true;
    return false;
}

int main()
{

    return 0;
}