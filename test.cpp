#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    while (cin >> x)
    {
        cout << (x & -x) << endl;
    }
    return 0;
}
