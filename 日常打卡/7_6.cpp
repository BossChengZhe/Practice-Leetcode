#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> numbers;
        set<string> foodItems;
        for (size_t i = 0; i < orders.size(); i++)
        {
            numbers.insert(orders[i][1]);
            foodItems.insert(orders[i][2]);
        }
        vector<vector<string>> res;
        vector<string> tempres;
        tempres.push_back("Table");
        for (auto iter = foodItems.begin(); iter != foodItems.end(); iter++)
        {
            tempres.push_back(*iter);
        }
        res.push_back(tempres);

        map<int, vector<int>> temp;
        for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
        {
            temp[stoi(*iter)].resize(foodItems.size(), 0);
        }

        for (size_t i = 0; i < orders.size(); i++) {
            temp[stoi(orders[i][1])][lower_bound(tempres.begin() + 1, tempres.end(), orders[i][2]) - tempres.begin() - 1]++;
        }

        
        for (auto iter = temp.begin(); iter != temp.end(); iter++)
        {
            tempres.clear();
            tempres.push_back(to_string(iter->first));
            for (size_t i = 0; i < iter->second.size(); i++)
            {
                tempres.push_back(to_string(iter->second[i]));
            }
            res.push_back(tempres);
        }
        return res;
    }
};