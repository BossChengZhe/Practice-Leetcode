#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return find(nums, k - 1, 0, nums.size() - 1);
    }
    int find(vector<int> &nums, int k, int left, int right)
    {
        if (left > right)
            return -1;
        // printf("%d %d\n", left, right);
        int temp = nums[left];
        int i = left, j = right;
        while (i < j)
        {
            while (j > i && nums[j] < temp)
                j--;
            while (i < j && nums[i] >= temp)
            {
                // cout << nums[i] << endl;
                i++;
            }

            // printf("%d %d\n", nums[i], nums[j]);
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        // cout << j << endl;
        nums[left] = nums[i];
        nums[i] = temp;
        if (k == i)
            return nums[i];
        else if (k > i)
            return find(nums, k, i + 1, right);
        else
            return find(nums, k, left, i - 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    Solution a;
    int res = a.findKthLargest(nums, 6);
    cout << res << endl;
    return 0;
}
