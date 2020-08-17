#include "iostream"
#include "vector"
#include "string"
#include "stack"
using namespace std;

bool isValid(string s) {
    stack<char> sp;
    for (int i = 0; i< s.length();i++)
    {
        if (s[i]=='('||s[i]=='{'||s[i]=='[')
            sp.push(s[i]);
        else if ((s[i]=='}' && !sp.empty()&&sp.top()=='{')||
            (s[i]==')' && !sp.empty()&&sp.top()=='(')||
            (s[i]==']' && !sp.empty()&&sp.top()=='['))
            sp.pop();
        else
            return false;
    }
    bool tmp = sp.empty();
    return sp.empty();
}

int main()
{
    isValid("()");
    return 0;
}