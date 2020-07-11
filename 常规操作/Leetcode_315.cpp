#include "algorithm"
#include "iostream"
#include "map"
#include "vector"
using namespace std;

void get_map(vector<int> nums, map<int, int> &ls)
{
    vector<int> no_nums;
    sort(nums.begin(), nums.end());
    int cur = nums[0];
    no_nums.push_back(cur);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != cur)
        {
            no_nums.push_back(nums[i]);
            cur = nums[i];
        }
    }
    for (int i = 0; i < no_nums.size(); i++)
        ls[no_nums[i]] = i + 1;
    return;
}

int low(int x)
{
    return x & -x;
}

void updata(vector<int> &c, int i)
{
    while (i < c.size())
    {
        c[i]++;
        i += low(i);
    }
    return;
}

int query(vector<int> &c, int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += c[i];
        i -= low(i);
    }
    return sum;
}

vector<int> countSmaller(vector<int> &nums)
{
    vector<int> res(nums.size(), 0);
    map<int, int> ls;
    get_map(nums, ls);
    vector<int> c(ls.size() + 1, 0);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int rank = ls[nums[i]];
        res[i] = query(c, rank);
        updata(c, rank);
    }
    return res;
}

int main()
{
    vector<int> res = {5,2,6,1,6};
    countSmaller(res);
    return 0;
}