#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    int cnt = 0;
    int up = 0, left = 0, right = n - 1, down = n - 1;
    for (int i = 0; i < (n / 2) + n % 2; i++)
    {
        if(left==right)
            matrix[left][up] = ++cnt;
        for (int j = left; j < right; j++)
            matrix[up][j] = ++cnt;
        for (int j = up; j < down; j++)
            matrix[j][right] = ++cnt;
        for (int j = right; j > left; j--)
            matrix[down][j] = ++cnt;
        for (int j = down; j > up; j--)
            matrix[j][left] = ++cnt;
        right--;
        left++;
        up++;
        down--;
    }
    return matrix;
}