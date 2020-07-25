#include "iostream"
#include "stack"
#include "vector"
#include "cmath"
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    vector<int> new_height(heights.size() + 2, 0);
    for (int i = 0; i < heights.size(); i++)
        new_height[i + 1] = heights[i];

    st.push(0);
    int res = 0;
    for (int i = 1; i < new_height.size(); i++)
    {
        while (new_height[st.top()] > new_height[i])
        {
            int he = st.top();
            st.pop();
            res = max(res, new_height[he] * (i - 1 - st.top()));
        }
        st.push(i);
    }
    return res;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    if (!matrix.size())
        return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> height(n, 0);
    int nums = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int res = 0;
            if (matrix[i][j] != '0')
            {
                for (int k = i; k >= 0 && matrix[k][j] != '0'; k--)
                    res++;
            }
            height[j] = res;
        }
        cout << endl;
        nums = max(largestRectangleArea(height), nums);
        vector<int>(n, 0).swap(height);
    }
    return nums;
}

int maximalRectangle2(vector<vector<char>> &matrix)
{
    if (!matrix.size())
        return 0;
    int area_max = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> height(n, 0), left(n, 0), right(n, n);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            height[j] = matrix[i][j] == '0' ? 0 : ++height[j];
        int current_left = 0;
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j]=='0')
            {
                left[j] = 0;
                current_left = j + 1;
            }
            else
                left[j] = max(current_left, left[j]);
        }
        int current_right = n;
        for (int j = n - 1; j >= 0;j--)
        {
            if(matrix[i][j]=='0')
            {
                current_right = j;
                right[j] = n;
            }
            else
                right[j] = min(current_right, right[j]);
        }
        for(int j = 0; j < n; j++)
            area_max = max(area_max, height[j] * (right[j] - left[j]));
    }
    return area_max;
}