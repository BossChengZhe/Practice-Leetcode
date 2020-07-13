#include "iostream"
#include "vector"
using namespace std;

/***********************************************************
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> column, row;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(!matrix[i][j])
            {
                column.push_back(j);
                row.push_back(i);
            }
    for(int i = 0; i < row.size(); i++)
        vector<int>(n, 0).swap(matrix[row[i]]);
    for(int i = 0; i < column.size(); i++)
        for(int j = 0; j < m; j++)
            matrix[j][column[i]] = 0;
    return;
}
***********************************************************/
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    bool flag_c = false, flag_r = false;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(!matrix[i][j])
            {
                if(i==0)
                    flag_r = true;
                if(j==0)
                    flag_c = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
    for(int i = 0; i < m; i++)
        if(matrix[i][0]==0)
            for(int j = 0; j < n; j++)
                matrix[i][j] = 0;
    for(int i = 0; i < n; i++)
        if(matrix[0][i]==0)
            for(int j = 0; j < m; j++)
                matrix[j][i] = 0;
    if(flag_r)
        for(int i = 0; i < n; i++)
            matrix[0][i] = 0;
    if(flag_c)
        for(int i = 0; i < m; i++)
            matrix[i][0] = 0;
}