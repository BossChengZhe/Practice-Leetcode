#include "iostream"
#include "stack"
#include "cmath"
#include "vector"
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    vector<int> new_height(heights.size() + 2, 0);
    for(int i = 0; i < heights.size(); i++)
        new_height[i + 1] = heights[i];
    
    st.push(0);
    int res = 0;
    for (int i = 1; i < new_height.size(); i++)
    {
        while (!st.empty() && new_height[st.top()] > new_height[i])
        {
            int he = st.top();
            st.pop();
            res = max(res, new_height[he] * (i-1-st.top()));
        }
        st.push(i);
    }
    return res;
}

int main()
{
    vector<int> height = {2, 1, 5, 6, 7, 3};
    largestRectangleArea(height);
    return 0;
}