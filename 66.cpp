#include "iostream"
#include "vector"
using namespace std;

/********************************************************************************************
 * 寻找在整数对中只出现一次的第一个数
 * 在示例中3和5只出现了一次，所以对应3、5只雇佣了一个人
 * 雇佣的人自然就是留下来加班的人也就是6、7
 * 我这边输出0表示没有人加班
********************************************************************************************/



int main()
{
    int num = 0;
    cin >> num;
    // 在树中7个节点共有6个连接点
    vector< vector<int> > employee(num - 1, vector<int>(2));
    for(int i = 0; i < employee.size(); i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        employee[i][0] = temp1;
        employee[i][1] = temp2;
    }

    vector<int> count(num);
    for(int i = 0; i < employee.size(); i++)
    {
        count[employee[i][0]] = count[employee[i][0]] + 1;
    }

    vector<int> res;

    for(int i = 0; i < num; i++)
    {
        if(count[i] == 1)
        {
            for(int j = 0; j < employee.size(); j++)
            {
                if(employee[j][0] == i)
                    res.push_back(employee[j][1]);
            }
        }
    }
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    if (res.size() == 0)
        cout << 0;
    cout << endl;
    return 0;
}