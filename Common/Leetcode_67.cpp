#include "iostream"
#include "string"
using namespace std;

void judge(string &res, int &temp, string a, string b, int &i, int &j)
{
    if ((a[i] == '1' && b[j] == '1' && temp == 0) || (temp == 1 && (a[i] == '1' || b[j] == '1')))
    {
        temp = 1;
        res.insert(0, "0");
    }
    else if (a[i] == '1' && b[j] == '1' && temp == 1)
    {
        temp = 1;
        res.insert(0, "1");
    }
    else if (a[i] == '1' || b[j] == '1' || temp == 1)
    {
        temp = 0;
        res.insert(0, "1");
    }
    else
    {
        temp = 0;
        res.insert(0, "0");
    }
}

string addBinary(string a, string b)
{
    int i = a.size() - 1, j = b.size() - 1, temp = 0;
    string res;
    while (i >= 0 && j >= 0)
    {
        temp = (a[i] - '0') + (b[j] - '0') + temp;
        res.insert(0, to_string(temp % 2));
        temp = temp / 2;
        i--;
        j--;
    }
    while(i>=0)
    {
        temp = (a[i] - '0') + temp;
        res.insert(0, to_string(temp % 2));
        temp = temp / 2;
        i--;
    }
    while(j>=0)
    {
        temp = (b[j] - '0') + temp;
        res.insert(0, to_string(temp % 2));
        temp = temp / 2;
        j--;
    }
    if(temp)
        res.insert(0, "1");
    return res;
}