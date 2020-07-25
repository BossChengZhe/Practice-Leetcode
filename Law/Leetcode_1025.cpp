#include "iostream"
#include "vector"
using namespace std;

bool divisorGame(int N)
{
    vector<bool> flag(N + 1, false);
    flag[2] = true;
    for (int i = 3; i < N + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0 && !flag[i - j])
            {
                flag[i] = true;
                break;
            }
        }
    }
    return flag[N];
}