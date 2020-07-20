#include "iostream"
#include "vector"
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    if(!nums.size())
        return 0;
    int i = 0, j = 0;
    while(j<nums.size())
    {
        if(nums[j]!=val){
            nums[i++] = nums[j];
        }
        j++;
    }
    return i;
}