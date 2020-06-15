#include "iostream"
#include "vector"
using namespace std;

int cur(vector<int> &nums, int target, int low, int high, int flag)
{
    if (low == high || (low == high - 1 && nums[high] != target && nums[low] == target))
        return low;
    if (nums[(low + high) / 2] > target)
        return cur(nums, target, low, (low + high) / 2 - 1, flag);
    else if (nums[(low + high) / 2] < target)
        return cur(nums, target, (low + high) / 2 + 1, high, flag);
    else
    {
        if (!flag)
            return cur(nums, target, low, (low + high) / 2, flag);
        else
        {
            if (high == low + 1)
            {
                if (nums[high] == target)
                    return high;
                else
                    return low;
            }
            else
                return cur(nums, target, (low + high) / 2, high, flag);
        }
    }
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> res{0, 0};
    if (!nums.size())
        return {-1, -1};
    if (nums.size() == 1 && nums[0] == target)
        return {0, 0};
    else if (nums.size() == 1 && nums[0] != target)
        return {-1, -1};

    int low = 0, high = nums.size() - 1, mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
            break;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (nums[mid] != target)
        return {-1, -1};
    else
    {
        // flag是指示当前查询的是左区间还是右区间
        res[0] = cur(nums, target, low, mid, 0);
        res[1] = cur(nums, target, mid, high, 1);
    }
    return res;
}

int main()
{
    vector<int> nums = {5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 10};
    vector<int> res = searchRange(nums, 7);
    for (auto as : res)
        cout << as << endl;
    return 0;
}