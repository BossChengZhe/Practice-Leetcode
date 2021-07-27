#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [](vector<int> a, vector<int> b)
             { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
        
        // 合并区间
        vector<vector<int>> new_ranges;
        int left1 = ranges[0][0], right1 = ranges[0][1];
        for (size_t i = 1; i < ranges.size(); i++)
        {
            if(right1 >= ranges[i][0] && right1 < ranges[i][1]) {
                right1 = ranges[i][1];
            }
            if(right1 < ranges[i][0]) {
                new_ranges.push_back({left1, right1});
                left1 = ranges[i][0];
                right1 = ranges[i][1];
            }
        }
        new_ranges.push_back({left1, right1});

        for (size_t i = 0; i < new_ranges.size(); i++){
            cout << new_ranges[i][0] << " " << new_ranges[i][1] << endl;
        }

        for (size_t i = 0; i < new_ranges.size(); i++)
        {
            if(left >= new_ranges[i][0] && right <= new_ranges[i][1]) {
                return true;
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
