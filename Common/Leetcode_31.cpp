#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

void nextPermutation(vector<int> &nums)
{
    if(nums.size()==1)
        return;
    int pre = -1, next = -1;
    for(int i = nums.size()-2; i >=0 ; i--)
    {
        if(nums[i]<nums[i+1]){
            // 找到了从右至左第一个比右边小的数字
            pre = i;
            int diff = INT_MAX;
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j]>nums[i]&&diff>nums[j]-nums[i])
                {
                    diff = nums[j] - nums[i];
                    next = j;
                }
            }
            diff = nums[next];
            nums[next] = nums[i];
            nums[i] = diff;
            sort(nums.begin() + i+1, nums.end());
            break;
        }
    }
    if(pre==-1&&next==-1)
        sort(nums.begin(), nums.end());
    return;
}

int main()
{
    vector<int> nums={1,3,2};
    nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i];
    return 0;
}