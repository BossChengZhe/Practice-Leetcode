#include "iostream"
#include "vector"
using namespace std;

void re(vector<vector<int>> &matrix, int &start, int &end)
{
    if (start - end + 1 == 1){
        start--;
        end++;
        return;
    }
        
    for (int i = start; i < end; i++)
    {
        int x = start, y = i;
        vector<int> temp;
        temp.push_back(matrix[x][y]);
        for (int j = 0; j < 4; j++)
        {
            temp.push_back(matrix[y][matrix.size() - 1 - x]);
            matrix[y][matrix.size() - 1 - x] = temp[j];
            int temp_x = y, temp_y = matrix.size() - 1 - x;
            x = temp_x;
            y = temp_y;
        }
    }
    start--;
    end++;
}

void rotate(vector<vector<int>> &matrix)
{
    int start = 0, end = 0;
    if (matrix.size() % 2 == 0)
    {
        start = matrix.size() / 2 - 1;
        end = matrix.size() / 2;
    }
    else
    {
        start = matrix.size() / 2;
        end = start;
    }
    while(start>=0)
        re(matrix, start, end);
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    return 0;
}