> ## [45.跳跃游戏II](https://leetcode-cn.com/problems/jump-game-ii/)
&emsp;&emsp;贪心算法寻找最优解，总是寻找当前`posmax`之前寻找最大的路径，比如说在开始是，最高可以跳两步，那么我们就需要遍历这两步的下一步谁跳的更远，很明显，第一次跳一步，跳到下标为`1`的位置，然后再跳的范围更远，所以我们选择跳一步，接下来的步骤跟这个相同
<div align=center>
<img src="../Image/45.png">
</div>

> ## [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)
&emsp;&emsp;与[跳跃游戏II](https://leetcode-cn.com/problems/jump-game-ii/)相同的原理，也是采用贪心法做，但是不需要关心最短几步可以走到终点，而是能否到达终点，所以只需要关心在区间内，是否无论怎么跳都会跳到值为0的点上，如果可以成功跳过那么返回`true`否则返回`false`
```C++
for (int i = 0; i < nums.size(); i++)
{
    if (i <= max_pos)
    // 判断是否在合理的区间范围内
    {
        max_pos = max(max_pos, i + nums[i]);
        if (max_pos >= nums.size() - 1)
            return true;
    }
}
```