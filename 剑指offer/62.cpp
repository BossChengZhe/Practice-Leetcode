#include "iostream"
#include "vector"
#include "queue"
using namespace std;

// int lastRemaining(int n, int m) {
//     queue<int> q;
//     for(int i = 0; i < n; i++)
//     {
//         q.push(i);
//     }
//     for(int i = 0; i < n-1; i++)
//     {
//         for(int j = 0; j < m-1; j++)
//         {
//             q.push(q.front());
//             q.pop();
//         }
//         q.pop();
//     }
//     return q.front();
// }
// 超时了

int lastRemaining(int n, int m) {
    int ans = 0;
    for(int i = 2; i <= n; i++)
    {
        ans = (ans + m) % i;
    }
    return ans;
}