#include "iostream"
#include "vector"
using namespace std;

int minOperations(int n) 
{
    int res = 0, temp = 0;
    if (n%2)
        temp =1;
    else
        temp = 2;
    for(int i = 0; i < n/2; i++)
    {
        res+=temp;
        temp+=2;
    }
    return res;
}