#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N, 0);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end(), greater<int>());
    vector<vector<int>> dp_0(N, vector<int>(2, 0));
    vector<vector<int>> dp_1(N, vector<int>(2, 0));
    dp_0[0][0] = nums[0];
    dp_1[0][1] = nums[0];
    for(int i = 1; i < N; i++)
    {
        // 当前货物放在第一个仓库中
        if(max(dp_0[i-1][0]+nums[i], dp_0[i-1][1]) > max(dp_1[i-1][0]+nums[i], dp_1[i-1][1]))
        {
            dp_0[i][0] = dp_1[i-1][0]+nums[i];
            dp_0[i][1] = dp_1[i-1][1];
        }   
        else
        {
            dp_0[i][0] = dp_0[i-1][0]+nums[i];
            dp_0[i][1] = dp_0[i-1][1];
        }
        // 当前货物放在第二个仓库中
        if(max(dp_0[i-1][0], dp_0[i-1][1]+nums[i]) > max(dp_1[i-1][0], dp_1[i-1][1]+nums[i]))
        {
            dp_1[i][0] = dp_1[i-1][0];
            dp_1[i][1] = dp_1[i-1][1]+nums[i];
        }
        else
        {
            dp_1[i][0] = dp_0[i-1][0];
            dp_1[i][1] = dp_0[i-1][1]+nums[i];
        }
    }
    cout << min(max(dp_0[N-1][0], dp_0[N-1][1]), max(dp_1[N-1][1],dp_1[N-1][0])) << endl;
    return 0; 
}   