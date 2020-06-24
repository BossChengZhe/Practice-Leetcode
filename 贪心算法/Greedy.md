> ## [45.跳跃游戏II](https://leetcode-cn.com/problems/jump-game-ii/)
&emsp;&emsp;贪心算法寻找最优解，总是寻找当前`posmax`之前寻找最大的路径，比如说在开始是，最高可以跳两步，那么我们就需要遍历这两步的下一步谁跳的更远，很明显，第一次跳一步，跳到下标为`1`的位置，然后再跳的范围更远，所以我们选择跳一步，接下来的步骤跟这个相同
<div align=center>
<img src="../Image/45.png">
</div>