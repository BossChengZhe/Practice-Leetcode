#include "iostream"
#include "stack"
#include "string"
#include "vector"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    void cur_en(TreeNode *root, string &res)
    {
        if (!root)
        {
            res += "n,";
            return;
        }
        else
        {
            res += to_string(root->val);
            res += ',';
            cur_en(root->left, res);
            cur_en(root->right, res);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null";
        string res;
        cur_en(root, res);
        res.pop_back();
        return res;
    }

    string get_next(string data, int &start)
    {
        string res;
        if (start == data.size())
            return "";
        for (int i = start; i < data.size(); i++)
        {
            start++;
            if (data[i] == ',')
                break;
            res += data[i];
        }

        return res;
    }

    TreeNode *cur_de(string data, int &start)
    {
        if(data.size()==start)
            return NULL;
        string temp = get_next(data, start);
        if (temp == "n")
            return NULL;

        TreeNode *root = new TreeNode(stoi(temp));
        root->left = cur_de(data, start);
        root->right = cur_de(data, start);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "null")
            return NULL;
        int start = 0;
        return cur_de(data, start);
    }
};