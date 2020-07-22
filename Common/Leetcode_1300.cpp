#include "algorithm"
#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

int findBestValue(vector<int> &arr, int target)
{
    // 二分加指针实现test
    sort(arr.begin(), arr.end());
    int sum = 0;
    for(auto s: arr)
        sum += s;
    if(sum<=target)
        // 如果和比target还要小，那就不需要缩小
        return arr[arr.size() - 1];
    sum = 0;
    int x = 0, temp_sum =0;
    for(int i = 0; i < arr.size(); i++)
    {
        temp_sum += arr[i];
        if(temp_sum+arr[i]*(arr.size()-1-i)>=target){
            x = i;
            sum = temp_sum - arr[i];
            break;
        }
    }
    int low = 0, high = 0,mid=0;
    int dis =INT_MAX, res=0;
    high = arr[x];
    if(x)
        low = arr[x - 1];
    while(low<=high){
        mid = (low + high) / 2;
        int zz = sum + mid * (arr.size() - x) - target;
        if(dis>abs(zz)){
            res = mid;
            dis = abs(zz);
        }
        if(sum+mid*(arr.size()-x)>target)
            high = mid - 1;
        else  if(sum+mid*(arr.size()-x)<target)
            low = mid + 1;
        else
            return mid;
    }
    return res;
}

int main()
{
    vector<int> arr={60864,25176,27249,21296,20204};
    int x = findBestValue(arr, 56803);
    cout << x << endl;
    return 0;
}