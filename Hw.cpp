#include <bits/stdc++.h>
using namespace std;


vector<bool> visit(16, false);
int res = INT_MAX;

void dfs(vector<vector<int>> &temp, int k, vector<vector<int>> &program, int num) {
    if(temp.size() == num) {
        int t = 0;
        for (size_t j = 0; j < temp.size(); j++)
        {
            t = max(t, temp[j][2]);
        }
        res = min(t, res);
    }
    for (size_t i = k; i < program.size(); i++)
    {
        if(!visit[program[i][0]] && !visit[program[i][1]]) {
            temp.push_back(program[i]);
            visit[program[i][0]] = true;
            visit[program[i][1]] = true;
            dfs(temp, i + 1, program, num);
            visit[program[i][0]] = false;
            visit[program[i][1]] = false;
            temp.pop_back();
        }
    }
}

int handler(vector<vector<int>> &program, int num) {
    vector<vector<int>> temp;
    dfs(temp, 0, program, num);
    return res;
}


int main(int argc, char const *argv[])
{
    int num = 2;
    vector<vector<int>> program{{0, 1, 250}, {0, 3, 10}, {1, 2, 25}, {1,3,80}, {2,3,90}};
    int r = handler(program, num);
    cout << r << endl;
    return 0;
}
