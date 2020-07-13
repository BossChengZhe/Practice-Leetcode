#include "algorithm"
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

/***********************************************************
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if(nums1[i]<nums2[j])
            i++;
        else if(nums1[i]<nums2[j])
            j++;
        else
        {
            res.push_back(nums1[i++]);
            j++;
        }
    }
    return res;
}
***********************************************************/
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> temp;
    vector<int> res;
    for(auto &s:nums1)
        temp[s]++;
    for(auto &x:nums2)
    {
        if(temp[x])
        {
            res.push_back(x);
            temp[x]--;
        }
    }
    return res;
}