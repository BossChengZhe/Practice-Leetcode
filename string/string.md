> ## [491. 递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/)
递归去子序列的模板 
```C++
vector<vector<int>> ans;
vector<int> temp;
void dfs(int cur, vector<int>& nums) {
    if (cur == nums.size()) {
        // 判断是否合法，如果合法判断是否重复，将满足条件的加入答案
        if (isValid() && notVisited()) {
            ans.push_back(temp);
        }
        return;
    }
    // 如果选择当前元素
    temp.push_back(nums[cur]);
    dfs(cur + 1, nums);
    temp.pop_back();
    // 如果不选择当前元素
    dfs(cur + 1, nums);
}
```
本题中，取得子序列之后还需要去重，保证在最终结果集合中不会出现重复数组，需要对重复数去重，只有四种情况
* 前者选择，后者选择
* 前者选择，后者不选择
* 前者不选择，后者选择
* 前者不选择， 后者不选择

其中，第二种和第三种事实上是等价的，所以舍弃了第二种，保留第三种。按照描述，只有当前数大于等于最后选择的数才可以进入下一层的搜索。