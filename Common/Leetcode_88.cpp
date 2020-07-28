#include "iostream"
#include "vector"
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (!n)
        return;
    if (!m)
    {
        nums1.swap(nums2);
        return;
    }
    int end = m + n - 1;
    int i = m - 1, j = n - 1;
    for (int k = end; k >= 0; k--)
    {
        if ((i >= 0 && j >= 0 && nums1[i] > nums2[j]) || (i >= 0 && j < 0))
            nums1[k] = nums1[i--];
        else if ((i >= 0 && j >= 0 && nums1[i] <= nums2[j]) || (i < 0 && j >= 0))
            nums1[k] = nums2[j--];
    }
}