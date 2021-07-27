#include <bits/stdc++.h>
using namespace std;

/*
* 返回值为1表示大，返回值为-1表示小
*/
int binary(int value, int cnt, vector<int> &nums) {
    int pos = lower_bound(nums.begin(), nums.end(), value) - nums.begin();  // C++自带二分库函数
    int num = nums.size() - pos;

    if(value > INT_MAX/num || value * num > cnt) {
        return 1;
    }
    int sum = value * num;
    for (size_t i = 0; i < pos; i++)
    {
        if(sum >= INT_MAX - nums[i] || sum > cnt)
            return 1;
        sum += nums[i];
    }
    if(sum <= cnt)
        return -1;
    else 
        return 1;
}


int handler(vector<int> &nums, int cnt) {
    sort(nums.begin(), nums.end());

    int max_value = INT_MIN;
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(sum > cnt)
            break;
    }
    if(sum <= cnt) {
        return -1;
    }
    
    int left = nums[0], right = nums.back();
    while (left < right)
    {
        int mid = (right - left) / 2 + left;
        if(binary(mid, cnt, nums) == -1)
            left = mid + 1;
        else
            right = mid;
    }
    return left == 0 ? left : left - 1;
}


int main(int argc, char const *argv[])
{
    vector<int> nums{1, 3, 6, 9, 10, 12,200};
    int cnt = 13;
    int res = handler(nums, cnt);
    cout << res << endl;
    return 0;
}
