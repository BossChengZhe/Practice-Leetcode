#include "iostream"
#include "vector"
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if(!nums.size())
        return 0;
    int i = 0, j = 1;
    while(j<nums.size()){
        if(nums[i]!=nums[j]){
            nums[++i] = nums[j];
        }
        j++;
    }
    // for(int k = 0; k < j-i; k++)
    //     nums.pop_back();
    return i + 1;
}