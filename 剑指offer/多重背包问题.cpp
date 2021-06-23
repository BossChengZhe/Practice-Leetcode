#include <bits/stdc++.h>
using namespace std;

struct good{
    int v;
    int w;
    good(int a, int b): v(a), w(b) {}
};

int main(int argc, char const *argv[])
{
    vector<good> Goods;
    int N, V;
    cin >> N >> V;
    vector<int> dp(V + 1, 0);
    for(size_t i = 0; i < N; i++) {
        int v, w, n;
        cin >> v >> w >> n;
        // 将数字分解为2的整数幂，10 = 1 + 2 + 4 + 3，这四个数可完成10以内所有的数字组合，降低复杂度
        for(size_t k = 1; k <= n; k*=2) {
            n -= k;
            Goods.push_back({v * k, w * k});
        }
        if(n)
            Goods.push_back({v * n, w * n});
    }
    for(size_t i = 0; i < Goods.size(); i++) {
        int v = Goods[i].v, w = Goods[i].w;
        for(size_t j = V; j  >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
