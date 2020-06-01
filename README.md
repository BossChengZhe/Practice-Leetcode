# Practice-Leetcode
一个学生党Leetcode刷题之路，欢迎交流


## 16.最接近的三数之和
&emsp;&emsp;这题思路和之前[Leetcode15](https://leetcode-cn.com/problems/3sum/)特别相似只是由固定变为了最接近目标数的值
* 首先暴力的方法并不可取，暴力枚举会使程的时间复杂度达到$O(N^3)$量级
* 可以将“接近”这一概念转化成绝对值的形式就可以得到当前三数之和与$target$的距离
$$distance = abs(nums_1+nums_2+nums_3-target)$$
*  距离不断接近的过程可以借用三数之和等于固定值得思路，将数组排序后计算$nums_i+nums_j+nums_k$,如果$nums_i+nums_j+nums_k > target$, k--,如果$nums_i+nums_j+nums_k < target$，j++，$nums_i+nums_j+nums_k == target$直接返回结果
    
