#include "iostream"
#include "vector"
using namespace std;

int mySqrt(int x)
{
    int low = 0, high = x;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if ((long long)mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}