#include "iostream"
#include "vector"
using namespace std;

vector<int> divingBoard(int shorter, int longer, int k)
{
    vector<int> res;
    if (!k)
        return {};
    if (longer == shorter)
        return {shorter * k};
    int gap = longer - shorter, minlen = shorter * k;
    for (int i = 0; i <= k; i++)
    {
        res.push_back(minlen);
        minlen += gap;
    }

    return res;
}