> ## [46.全排列](https://leetcode-cn.com/problems/permutations/)
&emsp;&emsp;这一题就类似于[解数独](https://leetcode-cn.com/problems/sudoku-solver/)，都是属于回溯法的范畴，想要具体了解这个方法，推荐 [扒一扒回溯算法的裤子](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/)，这位大佬讲的比我好，我就直接拿来主义了，接下来有图有真相
<div align=center>
<img src="../Image/46.gif">
</div>

这种回溯法**个人认为**有个模板，就是**添加影响-递归-移除影响**
```C++
temp_res.push_back(temp);
cur(res, nums, temp_res);
temp_res.pop_back();
```
上文中第一行就是**添加影响**，第二行**递归**，第三行**移除影响**,这三个部分就是回溯部分的框架，其他的部分按照题目要求添加
