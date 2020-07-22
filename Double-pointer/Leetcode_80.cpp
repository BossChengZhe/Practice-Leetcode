#include "iostream"
#include "vector"
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    if(n<2)
        return n;
    int slow = 0, cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(nums[i]!=nums[slow])
        {
            nums[++slow] = nums[i];
            cnt = 1;
        }
        else
        {
            if(cnt < 2)
            {
                nums[++slow] = nums[i];
                cnt++;
            }
        }
    }
    return slow + 1;
}

