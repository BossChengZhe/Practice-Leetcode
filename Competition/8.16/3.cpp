#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int find_(vector<int> &temp, int start, int &res, int m, int temp_res)
{
    for(int i = start; i < temp.size(); i++)
    {
        
    }
}

int maxDistance(vector<int>& position, int m)
{
    sort(position.begin(), position.end());
    int len = position.size();
    int cnt = 1, pre = position[0];
    vector<int> temp;
    temp.push_back(position[0]);
    for(int i = 1; i < len; i++)
    {
        if(position[i]!=pre)
        { 
            cnt++;
            pre = position[i];
            temp.push_back(position[i]);
        }
    }
    if (cnt<=m)
        return 0;
    
}