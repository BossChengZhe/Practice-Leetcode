#include "algorithm"
#include "iostream"
#include "stack"
#include "vector"
using namespace std;

// int trap(vector<int> &height)
// {
//     int res = 0;
//     stack<int> s;
//     for (int i = 0; i < height.size(); i++)
//     {
//         if(!s.empty()&&height[i]>=height[s.top()]){
//             int last = 0;
//             while(!s.empty()&&height[i]>=height[s.top()])
//             {
//                 last = s.top();
//                 s.pop();
//             }
//             if(!s.empty()){
//                 last = s.top();
//                 res += (height[i] * (i - last - 1));
//                 for(int j = i-1; j > last; j--)
//                 {
//                     res -= height[j];
//                     height[j] = height[i];
//                 }   
//             }
//             else{
//                 res += (height[last] * (i - last - 1));
//                 for(int j = i-1; j > last; j--)
//                 {
//                     res -= height[j];
//                     height[j] = height[last];
//                 }
//             }
             
//         }
//         s.push(i);
//     }
//     return res;
// }
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int x = trap(height);
    cout << x << endl;
    return 0;
}