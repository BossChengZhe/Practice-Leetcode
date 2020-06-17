#include "iostream"
#include "vector"
using namespace std;

int maxScoreSightseeingPair(vector<int> &A)
{
    if (A.size() == 2)
        return A[0] + A[1];
    int res = A[0] + A[1]-1, max = A[0] + 0;
    for (int i = 2; i < A.size(); i++)
    {
        cout << max << res << endl;
        max = (max < A[i - 1] + (i - 1)) ? A[i - 1] + (i - 1) : max;
        if (res < max + A[i] - i)
            res = max + A[i] - i;
    }
    return res;
}
int main()
{
    vector<int> A = {8, 1, 5, 2, 6};
    maxScoreSightseeingPair(A);
    return 0;
}