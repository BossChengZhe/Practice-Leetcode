#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    if(nums.size() < 4)
        return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> res(0, vector<int>(4));
    for(int i = 0; i < nums.size()-3; i++)
    {
        if(i&&nums[i] == nums[i-1])
                continue;
        for(int j = i+1; j < nums.size()-2; j++)
        {
            if(j!=i+1 && nums[j] == nums[j-1])
                continue;
            int n = j + 1, m = nums.size() - 1;
            int temp = nums[i] + nums[j];
            while(n < m ){
                if(nums[n]+nums[m]+temp<target)
                {
                    int flag = nums[n];
                    while (flag == nums[n] && n != nums.size()-1)
                        n++;
                }
                else if(nums[n]+nums[m]+temp>target)
                {
                    int flag = nums[m];
                    while (flag == nums[m] && m != 0)
                        m--;
                }
                else{
                    res.push_back({nums[i], nums[j], nums[n], nums[m]});
                    int flag = nums[n];
                    while (flag == nums[n] && n != nums.size()-1)
                        n++;
                    flag = nums[m];
                    while (flag == nums[m] && m != 0)
                        m--;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    fourSum(nums, -1);
    return 0;
}