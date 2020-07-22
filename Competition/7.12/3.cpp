#include "algorithm"
#include "cmath"
#include "iostream"
#include "stack"
#include "vector"
using namespace std;

/******************************************************************************************************
void cur(vector<vector<int>> &edges, vector<double> &succProb, vector<bool> &visit, double &possibility, double &res, int start, int end, int curr)
{
    if (curr == end)
    {
        res = min(res, possibility);
        return;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i][0] == curr && !visit[edges[i][1]])
        {
            // 如果当前节点为起始，并且边另外一段的节点未被访问过
            possibility *= succProb[i];
            visit[i] = true;
            cur(edges, succProb, visit, possibility, res, start, end, edges[i][1]);
            possibility /= succProb[i];
            visit[i] = false;
        }
    }
    return;
}

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<bool> visit(n, false);
    double res = 1.1, possibility = 1;
    cur(edges, succProb, visit, possibility, res, start, end, start);
    return res == 1.1 ? 0 : res;
}
******************************************************************************************************/
void cur(vector<vector<double>> matrix, int start, int end, int curr, double &res, double &possibility, int n, vector<bool> &visit)
{
    if (curr == end)
    {
        res = res == 1.1 ? possibility : max(res, possibility);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (matrix[curr][i]&&!visit[i])
        {
            possibility *= matrix[curr][i];
            visit[curr] = true;
            cur(matrix, start, end, i, res, possibility, n, visit);
            possibility /= matrix[curr][i];
            visit[curr] = false;
        }
    }
    return;
}
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<vector<double>> matrix(n, vector<double>(n, 0));
    vector<bool> visit(n, false);
    for (int i = 0; i < edges.size(); i++)
    {
        matrix[edges[i][0]][edges[i][1]] = succProb[i];
        matrix[edges[i][1]][edges[i][0]] = succProb[i];
    }
    double res = 1.1, possibility = 1;
    cur(matrix, start, end, start, res, possibility, n, visit);
    return res == 1.1 ? 0 : res;
}