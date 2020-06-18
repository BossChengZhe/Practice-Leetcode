#include "iostream"
#include "vector"
#include "string"
using namespace std;

 struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 void cur(TreeNode *root, string &s, int level, int &start)
 {
    if(start==s.size())
        return;
    int time_level = 0;
    while(s[start]=='-')
    {
        start++;
        time_level++;
    }
    int temp_val = 0;
    while(s[start]!='-')
    {
        temp_val *= 10;
        temp_val += 
    }
  }

TreeNode *recoverFromPreorder(string S)
 {
     
 }