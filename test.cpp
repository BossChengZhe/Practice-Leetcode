#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> test{1, 2, 3, 4, 5};
    swap(test[0], test[1]);
    for(int a : test)
        cout << a << endl;
    return 0;
}


