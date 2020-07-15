#include "iostream"
#include "vector"
using namespace std;

void sortColors(vector<int> &nums)
{
    // 两趟扫描
    vector<int> te(3, 0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
        te[nums[i]]++;
    int cnt = te[0], col = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt)
        {
            nums[i] = col;
            cnt--;
        }
        else
        {
            for (int j = col + 1; j < 3; j++)
            {
                if (te[col])
                    break;
                col = j + 1;
            }
            nums[i] = col;
            cnt = te[col];
        }
    }
}

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void sortColors2(vector<int> &nums)
{
    // 三指针法一次遍历
    int i = 0, j = nums.size() - 1, k = i;
    while (k <= j)
    {
        if (nums[k] == 2)
        {
            swap(nums, k, j);
            j--;
        }
        else if (nums[k] == 0 && k >= i)
        {
            swap(nums, k, i);
            k++;
            i++;
        }

        else
            k++;
    }
}