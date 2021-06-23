#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, V;
    cin >> N >> V;
    vector<int> dp(V + 1, 0);
    for(size_t i = 0; i < N; i++) {
        int vi, wi;
        cin >> vi >> wi;
        for(size_t j = V; j >= vi; j--) {
            dp[j] = max(dp[j], dp[j - vi] + wi);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
