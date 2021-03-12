#include <bits/stdc++.h>
using namespace std;

int m, n, p;
vector<int> a, b;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int m, n, p;
        cin >> n >> m >> p;
        a = vector<int>(n, 0);
        b = vector<int>(n, 0);
        for (int j = 0; j < m; j++)
            cin >> a[j];
        for (int j = 0; j < m; j++)
            cin >> b[j];
        int res = 0;
        vector<bool> visit(m, false);
    }
    return 0;
}
