#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            cout << mid << " " << arr[mid] << endl;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid] > arr[mid-1])
                low = mid;
            else if(arr[mid] > arr[mid+1])
                high = mid ;
            // break;
        }
        return high;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr{24,69,100,99,79,78,67,36,26,19} ;
    s.peakIndexInMountainArray(arr);
    return 0;
}
