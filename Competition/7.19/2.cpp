#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
#include "string"
#include "vector"
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

vector<int> find_son(vector<vector<int>> &edges, vector<vector<int>> &R_edges, int current, int father)
{
    int low = 0, high = edges.size() - 1;
    vector<int> sons;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (edges[mid][0] >= current)
            high = mid;
        else
            low = mid + 1;
    }
    for (int i = low; i < edges.size() && edges[i][0] == current; i++)
        if (edges[i][1] != father)
            sons.push_back(edges[i][1]);

    low = 0, high = edges.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (R_edges[mid][1] >= current)
            high = mid;
        else
            low = mid + 1;
    }
    for (int i = low; i < edges.size() && R_edges[i][1] == current; i++)
        if (R_edges[i][0] != father)
            sons.push_back(R_edges[i][0]);
    return sons;
}

void cur(int n, vector<vector<int>> &edges, string labels, vector<vector<int>> R_edges, int current, vector<int> &res, vector<int> &la, int father)
{
    vector<int> sons = find_son(edges, R_edges, current, father);
    if (sons.size() == 0)
    {
        la[labels[current] - 'a']++;
        res[current]++;
        return;
    }

    int temp = la[labels[current] - 'a'];
    la[labels[current] - 'a']++;
    for (int i = 0; i < sons.size(); i++)
        if (sons[i] != father)
            cur(n, edges, labels, R_edges, sons[i], res, la, current);
    res[current] = la[labels[current] - 'a'] - temp;
    return;
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    vector<int> res(n, 0), la(26, 0);
    sort(edges.begin(), edges.end(), cmp);
    vector<vector<int>> R_edges = edges;
    sort(edges.begin(), edges.end());
    cur(n, edges, labels, R_edges, 0, res, la, -1);
    return res;
}

int main()
{
    vector<vector<int>> edges = {{4, 0}, {5, 4}, {12, 5}, {3, 12}, {18, 3}, {10, 18}, {8, 5}, {16, 8}, {14, 16}, {13, 16}, {9, 13}, {22, 9}, {2, 5}, {6, 2}, {1, 6}, {11, 1}, {15, 11}, {20, 11}, {7, 20}, {19, 1}, {17, 19}, {23, 19}, {24, 2}, {21, 24}};
    string label = "hcheiavadwjctaortvpsflssg";
    countSubTrees(25, edges, label);
    return 0;
}