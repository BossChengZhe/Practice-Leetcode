#include "iostream"
#include "vector"
using namespace std;

bool isLongPressedName(string name, string typed)
{
    int size_name = name.length(), size_typed = typed.length();
    vector<vector<bool>> dp(size_name, vector<bool>(size_typed, false));
    for(int i = 0; i < size_typed; i++)
    {
        if(name[0]==typed[i])
            dp[0][i] = true;
        else
            break;
    }
    for(int i = 1; i < size_name; i++)
    {
        for(int j = i; j < size_typed; j++)
        {
            while(!dp[i-1][j])
                j++;
            j++;
            if(name[i]==typed[j])
                dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1];
        }
    }
    for(int i = 0; i < size_name; i++)
    {
        for(int j = 0; j < size_typed; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[size_name - 1][size_typed - 1];
}