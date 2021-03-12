#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int n, k;
        cin >> n >> k;
        vector<bool> bu(100000, false);
        int first = 0;
        for(int j = 0; j < n; j++)
        {
            int temp;
            scanf("%d", &temp);
            if(j==0)
                first = temp;
            bu[temp] = true;
        }
        int cnt = 0;
        for(int j = first + 1; j < 100000; j++)
        {
            if(!bu[j])
                cnt++;
            if(cnt == k)
            {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}
