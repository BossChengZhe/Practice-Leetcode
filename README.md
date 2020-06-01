# Practice-Leetcode
一个学生党Leetcode刷题之路，欢迎交流


## 16.最接近的三数之和
&emsp;&emsp;这题思路和之前[Leetcode15](https://leetcode-cn.com/problems/3sum/)特别相似只是由固定变为了最接近目标数的值
* 首先暴力的方法并不可取，暴力枚举会使程的时间复杂度达到$O(N^3)$量级
* 可以将“接近”这一概念转化成绝对值的形式就可以得到当前三数之和与$target$的距离
$$distance = abs(nums_1+nums_2+nums_3-target)$$
*  距离不断接近的过程可以借用三数之和等于固定值得思路，将数组排序后计算$nums_i+nums_j+nums_k$,如果$nums_i+nums_j+nums_k > target$, k--,如果$nums_i+nums_j+nums_k < target$，j++，$nums_i+nums_j+nums_k == target$直接返回结果
    
## 17.电话号码的字母组合
&emsp;&emsp;这题若是定长度数字字符，列举出所有的英文字符组合，可以很轻松的通过枚举的方式得出结果，但是输入字符不定长，嵌套的循环数目就不等，所以不能枚举方式列出所有的字符组合。
1. 递归回溯(不知道这样说正不正确，但这个是我的理解)
    - 循环数目不能够确定，可以通过递归的方式层层嵌套循环，累加
    ![](https://github.com/BossChengZhe/Practice-Leetcode/blob/master/Image/17.%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E9%80%92%E5%BD%92%E7%BB%93%E6%9E%84.jpg)