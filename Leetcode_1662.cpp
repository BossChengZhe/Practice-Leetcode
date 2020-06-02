#include "iostream"
#include "vector"
using namespace std;

void cur(int n, int &res)
{
    if(!n)
        return;
    res += n;
    return cur(n - 1, res);
}

int sumNums(int n)
{
    int res = 0;
    cur(n, res);
    return res;
}

int main()
{
    int res = sumNums(100);
    cout << res << endl;
    return 0;
}