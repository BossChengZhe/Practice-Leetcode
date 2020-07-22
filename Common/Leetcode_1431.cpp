#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    vector<int> temp = candies;
    sort(temp.begin(), temp.end(), greater<int>());
    vector<bool> res;
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= temp[0])
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;
}

vector<bool> kidsWithCandies2(vector<int> &candies, int extraCandies)
// 第二个版本，由于只需要找出最大值，所以没有必要对整个数组sort
{
    int max_can = candies[max_element(candies.begin(), candies.end()) - candies.begin()];
    vector<bool> res;
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= max_can)
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;
}

int main()
{

    return 0;
}