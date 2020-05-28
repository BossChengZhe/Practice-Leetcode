#include "iostream"
#include "vector"
using namespace std;

/*************************************************************************************************************
 * 双指针法的运用
 * 起始从数组两头开始，由题意很轻松得到面积的计算公式 Area = min(height[i], height[j]) * (j - i)
 * 接下来移动较小的权值较小的指针，i++或者j--
 * 当较小权值的指针不动，较大权重的指针移动的话，可以证明不论怎么移动，得到的区域面积始终小于当前面积，所以应该移动权值较低的一边 
*************************************************************************************************************/

int maxArea(vector<int> &height)
{
    int res = 0;
    int i = 0, j = height.size() - 1;
    while(i != j)
    {
        res = max(res, min(height[i], height[j]) * (j - i));
        if(height[j] > height[i])
            i++;
        else
            j--;
    }
    return res;
}

int main()
{
    vector<int> height = {8, 8, 6, 2, 5, 4, 8, 3, 7};
    int x = maxArea(height);
    cout << x << endl;
    return 0;
}