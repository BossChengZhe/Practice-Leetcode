#include "iostream"
#include "vector"
using namespace std;

int minArray(vector<int> &numbers)
{
    int low = 0, high = numbers.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (numbers[mid] > numbers[high])
            low = mid + 1;
        else if (numbers[mid] < numbers[high])
            high = mid;
        else
            low++;
    }
    return numbers[low];
}
