#include "iostream"
#include "queue"
#include "vector"
using namespace std;

class Solution
{
private:
    static constexpr int uncolored = 0;
    static constexpr int RED = 1;
    static constexpr int BLUE = 2;

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> COLORED(n, uncolored);
        for (int i = 0; i < n; i++)
        {
            if (COLORED[i] == uncolored)
            {
                queue<int> q;
                q.push(i);
                COLORED[i] = RED;
                while (!q.empty())
                {
                    int node = q.front();
                    int cl = (COLORED[node] == RED ? BLUE : RED);
                    q.pop();
                    for (auto neighbor : graph[node])
                    {
                        if (COLORED[neighbor] == uncolored)
                        {
                            q.push(neighbor);
                            COLORED[neighbor] = cl;
                        }
                        else if (COLORED[neighbor] != cl)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};