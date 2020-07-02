#include "iostream"
#include "vector"
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int temp = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        while(i+1!=nums[i]&&nums[i]>0&&nums[i]<=nums.size()&&nums[i]!=nums[nums[i]-1])
        {
            temp = nums[nums[i]-1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(i+1!=nums[i])
            return i + 1;
    }
    return nums.size() + 1;
}
int main()
{
    vector<int> nums = {3, 4, -1, 1};
    firstMissingPositive(nums);
    return 0;
}