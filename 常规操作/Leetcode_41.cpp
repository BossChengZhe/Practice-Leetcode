#include "iostream"
#include "vector"
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        while (i + 1 != nums[i] && nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
        {
            temp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[temp - 1] = temp;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return nums.size() + 1;
}