#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> ump;
    vector<int> nums;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(!ump.count(val)) {
            ump[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!ump.count(val))
            return false;

        int temp = nums.back();
        swap(nums.back(), nums[ump[val]]);
        ump[temp] = ump[val];
        ump.erase(val);
        nums.pop_back();

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % (int)nums.size();
        return nums[idx];
    }
};