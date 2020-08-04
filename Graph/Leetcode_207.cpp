#include "iostream"
#include "queue"
#include "vector"
using namespace std;

bool can_study(vector<vector<bool>> &graph, int z, vector<bool> &visit)
{
    for (int i = 0; i < graph.size(); i++)
        if (graph[i][z] && !visit[i])
            return false;
    return true;
}

bool canFinish1(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
    vector<bool> visit(numCourses, false);
    for (int i = 0; i < prerequisites.size(); i++)
        graph[prerequisites[i][0]][prerequisites[i][1]] = true;

    int cnt = 0;
    for (int i = 0; i < numCourses; i++)
    {
        if (visit[i])
            continue;
        int in = 0;
        for (int j = 0; j < numCourses; j++)
            in += graph[j][i] ? 1 : 0;
        if (in)
            continue;
        queue<int> q;
        q.push(i);
        visit[i] = true;
        cnt++;
        while (!q.empty())
        {
            int q_size = q.size();
            for (int k = 0; k < q_size; k++)
            {
                int node = q.front();
                q.pop();
                for (int z = 0; z < numCourses; z++)
                    if (graph[node][z] && !visit[z] && can_study(graph, z, visit))
                    {
                        q.push(z);
                        visit[z] = true;
                        cnt++;
                    }
            }
        }
    }
    return cnt == numCourses;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> degree(numCourses, 0);
    vector<vector<int>> edges(numCourses, vector<int>(0));
    for(int i = 0; i < prerequisites.size(); i++)
    {
        edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        degree[prerequisites[i][0]]++;
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++)
        if(degree[i]==0)
            q.push(i);

    int visit = 0;
    while(!q.empty())
    {
        visit++;
        int node = q.front();
        q.pop();
        for(auto &j:edges[node])
        {
            degree[j]--;
            if(!degree[j])
                q.push(j);
        }
    }
    return visit == numCourses;
}