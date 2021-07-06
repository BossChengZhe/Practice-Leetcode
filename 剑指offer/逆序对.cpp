#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> temp;
    int res = 0;
    int reversePairs(vector<int>& nums) {
        temp.resize(nums.size(), 0);
        mergeAndCount(nums, 0, nums.size() - 1);
        return res;
    }
    void mergeAndCount(vector<int>& nums, int left, int right) {
        if(left < right) {
            int mid = left + (right - left) / 2;
            mergeAndCount(nums, left, mid);
            mergeAndCount(nums, mid + 1, right);
            int i = left, j = mid + 1;
            int cnt = left;

            for (size_t i = left; i <= right; i++)
            {
                temp[i] = nums[i];
            }
            
            while(i <= mid && j <= right) {
                if(temp[i] <= temp[j])
                    nums[cnt++] = temp[i++];
                else {
                    res += (mid - i + 1);
                    nums[cnt++] = temp[j++];
                }
            }
            while(i <= mid) 
                nums[cnt++] = temp[i++];
            while(j <= right)
                nums[cnt++] = temp[j++];
        }
    }
};