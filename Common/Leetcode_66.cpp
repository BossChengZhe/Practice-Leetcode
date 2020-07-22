#include "iostream"
#include "vector"
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int c = 1;
    int n = digits.size() - 1;
    if (digits[n] + c < 10)
    {
        digits[n]++;
        return digits;
    }
    for (int i = n; i >= 0; i--)
    {
        int temp = digits[i];
        digits[i] = (temp + c) % 10;
        c = (temp + c) / 10;
        if (!c)
            return digits;
    }
    if (!c)
        return digits;
    digits.insert(digits.begin(), c);
    return digits;
}