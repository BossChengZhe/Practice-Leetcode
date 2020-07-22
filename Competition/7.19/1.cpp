#include "iostream"
#include "vector"
using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    int res = 0;
    int empty = 0;
    while (numBottles >= 0)
    {
        res += numBottles;
        int temp = empty;
        empty = (numBottles + empty) % numExchange;
        numBottles = (numBottles + temp) / numExchange;
    }
    return res;
}