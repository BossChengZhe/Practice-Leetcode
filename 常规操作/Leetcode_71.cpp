#include "iostream"
#include "string"
#include "vector"
using namespace std;

string simplifyPath(string path)
{
    vector<string> vs;
    string temp;
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] != '/')
            temp += path[i];
        else if (temp.size() != 0)
        {
            if (temp == ".." && vs.size() != 0)
                vs.pop_back();
            else if (temp != "." && temp != "..")
                vs.push_back(temp);
            temp = "";
        }
    }
    if (temp.size() != 0)
    {
        if (temp == ".." && vs.size() != 0)
            vs.pop_back();
        else if (temp != "." && temp != "..")
            vs.push_back(temp);
    }
    if (!vs.size())
        return "/";
    temp = "";
    for (int i = 0; i < vs.size(); i++)
    {
        temp += '/';
        temp += vs[i];
    }
    return temp;
}

int main()
{
    simplifyPath("/home/");
    return 0;
}