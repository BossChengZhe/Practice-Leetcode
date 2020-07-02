#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int findLength(vector<int> &A, vector<int> &B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    // 状态转移公式：dp[i][j]=(A[i-1]==B[j-1])?dp[i-1][j-1]+1:0;
    int max_size = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
            max_size = max(dp[i][j], max_size);
        }
    }
    return max_size;
}