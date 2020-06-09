#include "iostream"
#include "string"
#include "vector"
using namespace std;

int translateNum(int num)
{
    string temp = to_string(num);
    int p = 0, q = 1, r = 1;
    for (int i = 1; i < temp.size(); i++)
    {
        p = q;
        q = r;
        r = 0;
        r += q;
        int x = (temp[i - 1] - '0') * 10 + (temp[i] - '0');
        if (x >= 10 && x <= 25)
            r += p;
    }
    return r;
}

int main()
{
    int res = translateNum(12258);
    cout << res << endl;
    return 0;
}