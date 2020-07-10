#include "iostream"
#include "string"
#include "vector"
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> res;
    for (int i = 0; i < words.size(); i++)
    {
        int cnt = 0, word_length = 0; // 表示当前字符串中包含多少个单词。用于分配空格
        string temp_res;
        int j = i;
        while (i < words.size() && word_length- 1 <= maxWidth)
        {
            word_length += (words[i].size() + 1);
            cnt++;
            if (i < words.size() - 1 && word_length + words[i + 1].size() > maxWidth)
                break;
            i++;
        }
        cout << i << endl;
        if (i == words.size())
        {
            // 表示当前是最后一行，左对齐
            for (int k = j; k < i; k++)
            {
                temp_res += words[k];
                temp_res += ' ';
            }
            temp_res.pop_back();
            res.push_back(temp_res + string(maxWidth - temp_res.size(), ' '));
            break;
        }
        else
        {
            // 不是最后一行，该怎么样怎么样
            word_length -= cnt;
            int space_num = maxWidth - word_length;
            if (cnt == 1)
            {
                res.push_back(words[i] + string(space_num, ' '));
                continue;
            }
            int more = space_num % (cnt - 1), aver = space_num / (cnt - 1);
            for (int k = 0; k < more; k++)
                temp_res += (words[j++] + string(aver + 1, ' '));
            for (int k = j; k < i; k++)
                temp_res += (words[k] + string(aver, ' '));
            temp_res += words[i];
            res.push_back(temp_res);
        }
    }
    return res;
}

int main()
{
    vector<string> words = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
    vector<string> x = fullJustify(words, 30);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << endl;
    }
    return 0;
}