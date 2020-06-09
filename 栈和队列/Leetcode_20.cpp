#include "iostream"
#include "stack"
#include "vector"
using namespace std;

bool isValid(string s) {
    if(s.size() == 1)
        return false;
    stack<char> dec;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            dec.push(s[i]);
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            char temp = dec.top();
            dec.pop();
            if((s[i]==')' && temp!='(') || (s[i]=='}' && temp!='{') || (s[i]==']' && temp!='['))
                return false;
        }
    }
    if(!dec.empty())
        return false;
    return true;
}

int main()
{
    
    return 0;
}