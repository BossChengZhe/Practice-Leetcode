#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

vector<int> grayCode(int n)
{
    vector<bool> flag(pow(2, n), false);
    vector<int> res(pow(2, n), 0);
    int temp = 0;
    flag[temp] = true;
    for (unsigned int i = 1; i < pow(2, n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp ^= (1U << j);
            if (!flag[temp])
            {
                res[i] = temp;
                flag[temp] = true;
                break;
            }
            temp ^= (1U << j);
        }
    }
    return res;
}