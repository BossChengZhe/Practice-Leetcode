#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

bool isMonotonic(vector<int> &A)
{
    // bool tr = true, fl = true;
    // for (int i=0; i < A.size()-1;i++)
    // {
    //     if(A[i]>A[i+1])
    //         fl = false;
    //     if(A[i]<A[1+i])
    //         tr = false;
    // }
    return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());
}