> ## [面试题46.将数字翻译为字符串](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/)<br>
&emsp;&emsp;由题目可知，每一位数字单独翻译都是可以的，但当两位数字组合的时候，并不是每一对都可以被翻译为字母的，因为我们知道，一共只有26个英文字母，所以组合数$x$, <small>$10\leq x\leq 25$</small>，故需要判断。<br>
&emsp;&emsp;本题利用DP的原理，递推公式为，分成两种情况讨论
$$f(i)=f(i-1)+f(i-2)[i-1\geq 0,10\leq x\leq 25]$$
* 当第$i$个数字单独翻译时，就等于$f(i-1)$每一个翻译后的字符串加上第$i$个数字对应的字符翻译，而单个字符的翻译是肯定有效的，于是直接加上$f(i-1)$
* 当第$i$、$i-1$个字符在一起翻译，就需要检测当前数字的合理性，如果超出25或者小于两位数的最小值10都是无效的翻译，所以$x$必须在$[10,25]$范围内的

&emsp;&emsp;如上两种情况就得到了DP的递推公式

> ## [32.最长有效括弧](https://leetcode-cn.com/problems/-valid-parentheses/)
&emsp;&emsp;首先由有效括号的性质可以得到，有效括号都是由')'结尾的，所以以'('结尾的字符串都不是有效括号，所以可以采取分类讨论和动态规划的方式，解此问题，(`dp[i]`是以`i`结尾的有效括号的长度)
* 当`s[i]==')'&&s[i-1]=='('`时，即括号形式是"....()"，`dp[i]=dp[i-2]+2`<small>($x-2 \ge 0$)</small>
* 当`s[i]==')'&&s[i-1]==')'&&s[i-dp[i-1]-1]=='('`时,即括号形式是"...))"，`dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2`<small>($i-dp[i-1]-2 \ge 0$)</small>
    > `i-dp[i-1]-2`、`i-dp[i-1]-1`分别代表了什么，是当前动态规划的核心
> ## [70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)
&emsp;&emsp;这题解题思路有两条，第一条是递归的方法，第二条就是动态规划
* 递归的方法说来很简单，就是遍历在当前步长后遍历走1步和走2步之后所有的情况，但是由于重复的太多，导致时间复杂度很高，最后时间超限
* 当$n>2$时，最后一次走两步和走一步分别对应着`dp[n-2],dp[n-1]`，然后就得到了动态规划的递推公式，初始化`dp[1]=1,dp[2]=2`，然后就按照递推公式计算直到`dp[n]`
$$dp[i]=dp[i-2]+dp[i-1]$$

> ## [139.单词拆分](https://leetcode-cn.com/problems/word-break/)
&emsp;&emsp;单词拆分问题可以很轻易的拆解为当前单词与前面单词结果的结合，比如我遍历到`"leetcode"`中的`"code"`，经过查找，发现在词典中，于是我们查找之前，`dp[i-4]`看是否有效，有效当前为`true`，否则为`false`
&emsp;&emsp;当然查询也可以用其他的方法查，我用二分只是因为我只能想出二分的查找方式。

> ## [718.最长重复子数组](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)
&emsp;&emsp;DP的话，需要确定`dp[i][j]`代表的什么意思，在本题中表示在以`A[i]`和`B[j]`结尾的数组 `A`和 `B`前缀的最大公共后缀，那么状态转移公式就可以写为 
```C++
dp[i][j] = (A[i-1] ==  B[j-1]) ? dp[i - 1][j - 1] + 1 : 0;
```
&emsp;&emsp;需要注意的是，对于范围内任意`i`,`j`，`dp[i][j]`的值和其左上角的值有关，那么我们需要额外在原有的基础上加上一层数据，保证数组不越界，这也是代码中`dp`数组会在`A.size()`和`B.size()`上加1的原因。

> ## [53.最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)
&emsp;&emsp;每一个数组中元素只有两种情况，一个是在当前子序列和中，一个是不在，只需要判断该数前面的序列和加上该数与该数对比，取较大的那个。由于结果之和最后一个结果有关，所以只需要设置两个变量，达到$O(1)$空间占用。
$$f(i)=max(pre+nums_{i},nums_{i})$$

> ## [44.通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)
&emsp;&emsp;可以分解为前缀子序列的匹配子问题，当前状态与前面匹配状态相关，所以可以采用动态规划解题。
* 当匹配模式是字母时，并且与当前指向的字符相同时，<small>$dp_{i,j}=dp_{i-1,j-1}$</small>
* 当前匹配模式是"?"时，可以匹配任意字符，<small>$dp_{i,j}=dp_{i-1,j-1}$</small>
* 当前匹配模式指向的是"\*",那么有两种情况，一个是使用这个“\*”,那么 <small>$dp_{i,j}=dp_{i-1,j}$</small>;第二种情况是没有使用“\*”匹配字符串，那么 <small>$dp_{i,j}=dp_{i,j-1}$</small>
* 当然我们也需要注意边界情况，也就是字符串是否为空和匹配模式是否为空两个变量共四种情况分类讨论
    * 首先两者都不为空，需要计算得到
    * 字符串不为空，匹配模式为空，空的匹配模式不能匹配非空字符串，所以所有的 <small>$dp_{i,0}=false \quad 0<i \le size_j$</small>
    * 字符串为空，匹配模式不为空，只有"\*"可以匹配空字符串，需要匹配模式全部为"\*"时，才可以使得 <small>$dp_{0,j}=true \quad 0<j\le size_{p}$</small>
    * 全为空，即 <small>$dp_{0,0}=true$</small>

> ## <span id="62">[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)</span>
&emsp;&emsp;观察地图可以得到，由于机器人只能向下或者向上走，那么该位置的走法只跟当前位置的左边或者是右边有关系，那么一个就分解成为子问题，那么可以采用动态规划解该题
$$dp_{i,j}=dp_{i-1,j}+dp_{i,j-1}$$

> ## [63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)
&emsp;&emsp;观察地图可以得到，由于机器人只能向下或者向上走，当前位置如果不存在障碍物，那么该位置的走法只跟当前位置的左边或者是右边有关系，那么一个就分解成为子问题，那么可以采用动态规划解该题 
$$dp_{i,j}=dp_{i-1,j}+dp_{i,j-1} \quad if\quad obstacleGrid_{i,j}==1$$
**暴力解法**害死人，如果采用递归的方式计算，时间超限！！！

> ## [64.最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)
&emsp;&emsp;类似于 [不同路径II](#62)中的思路，该问题可以分解为子问题，即当前位置的最小距离是当前位置的上方位置和左方位置距离的较小值加上当前位置的值，所以可以得到状态转移公式，即 
$$dp_{i,j}=Grid_{i,j}+dp_{i-1,j}+dp_{i,j-1} \quad i,j>0$$
同时需要注意，处于第一行或者第一列的分别只能选择左边和上边的`dp`数组中的值。

> ## [309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
&emsp;&emsp;股票问题看上去很复杂，但是分解开，每一天总共有三种状态，按照这三种状态指定三种状态转移方程，就能够得到结果。
* 当前天状态为冷冻，那么由于冷冻期只有一天所以前一天肯定是卖出了股票，那么当前天的利润就等于前一天卖出的利润即 
$$
cool\_down_{i}= sell_{i-1} \quad i \ge0 
$$
* 当前天的状态为卖出，表示那么一定在之前买入了股票，可能是`i-1`天买入或者再往前，如果是昨天买入，只需要昨天买入利润加上今天的价格就是利润；如果是`i-1`天之前买的，那么需要考虑是`i-1`天卖，还是今天卖。那么利润就可以表示为 
$$
sell_i=max(buy_{i-1}+prices_i,sell_{i-1}) \quad i \ge 0
$$
* 当前天状态为买入，那么要么前一天刚刚买过或者是`i-1`之前是冷冻期，和上面的推算同理，有 
$$
buy_i=max(buy_{i-1}, cool_{i-1}-prices_{i}) \quad i \ge 0
$$

&emsp;&emsp;最终的返回值是不再持有股票的利润最大值即 `max(cool_down, sell)`

> ## [174. 地下城游戏](https://leetcode-cn.com/problems/dungeon-game/)
&emsp;&emsp;因为前面有类似的题目，所以我将毫不犹豫使用了从左上到右下的动态规划，结果返回了错误的值，经过查看题解得到，从左上到右下的动态规划违反了动态规划的无后效性，即前面的状态会影响到后面的状态，所以我们从右下往左上动态规划，假设计算`dp[i][j]`，那么`dp[i][j]`的值会受到`dp[i-1][j]`，`dp[i][j+1]`两处的影响，由于是取最小的值，并且该值大于等于1，所以状态转移方程是 
$$
dp_{i,j} = max(min(dp_{i+1,j},dp_{i,j+1})-dungeon_{i,j}, 1)
$$
同时我们需要对dp数组进行冗余处理，在右方和下方多加一行，并且将`dp[n][m-1]`和`dp[n-1][m]`设置为无效值，即可保证边界正确。

**无后效性**：如果给定某一阶段的状态，则在这一阶段以后过程的发展不受这阶段以前各段状态的影响，所有各阶段都确定时，整个过程也就确定了

> ## [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)
&emsp;&emsp;主要难点还是在分析动态规划状态转移过程，刚开始看到编辑距离的时候不知道怎么去计算当前，在这里我们设`dp[i][j]`为`words1`的前`i`字符构成的子串到`words2`的前`j`个字符构成的子串的编辑距离，那么分情况讨论。
* 如果 `words1[i]==word2[j]`，那么直接跳过，不需要任何操作即 
$$
dp_{i,j}=dp_{i-1,j-1} \quad i \ge 1 \quad j \ge 1
$$
* 如果`words1[i]!=word2[j]`，分为三种操作，分别是替换，插入，和删除
    * 替换，相当于将`words1`的第`i`字符替换成`words1`的第`j`字符，`words1[0:i-2]`转换成`words2[0:j-2]`，所以状态转移公式就是 
    $$
    dp_{i,j}=dp_{i-1,j-1}+1 \quad i \ge 1 \quad j \ge 1
    $$
    * 删除，将`words1[0:i-2]`转换成`words2[0:j-1]`并且将并且将第`i`个字符删除 
    $$
    dp_{i,j}=dp_{i-1,j}+1 \quad i \ge 1 \quad j \ge 1
    $$
    * 插入，将`words1[0:i-1]`转换成`words2[0:j-2]`并且将`words[j]`插入到`words1[i]`位置上 
    $$
    dp_{i,j}=dp_{i,j-1}+1 \quad i \ge 1 \quad j \ge 1
    $$
    
> ## [120. 三角形最小路径和](https://leetcode-cn.com/problems/triangle/)
&emsp;&emsp;很具有动态规划题目的特色，所以凭借直觉(狗头)应该使用动态规划完成这道题。`dp[i][j]`是达到三角形该坐标的最小距离，所以状态公式就可以写为
* 当 `i==j`，即当前位置在三角形该层的最右端 
$$
dp_{i,j}=dp_{i-1,j-1}+triangle_{i,j}
$$
* 当 `j==0`，即当前位置在三角形该层的最左端 
$$
dp_{i,j}=dp_{i-1,j}+triangle_{i,j}
$$
* 其他 
$$
dp_{i,j}=min(dp_{i-1,j-1},dp_{i-1,j})+triangle_{i,j}
$$

    > 这道题还有可以优化的空间，例如我们观察动态规划数组可以得到当前层仅仅只和上一层有关，而且当前层的有效值要比上一层多1，所以可以建立一个长为`n`的数组，每次按照上文的状态转移公式从后往前更新`dp`数组即可以优化为n，甚至可以直接在原数组上建立转移矩阵，实现`O(N)`级别的程序

> ## [96. 不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)
&emsp;&emsp; 这题本身思路很简单，只需要对每个结点啊作为根节点考虑所有情况累加，可以分解为小的子问题，比如说左子树有多少种情况。状态转移方程可以写为 
$$
dp_n = dp_0 \times dp_{n-1}+dp_1 \times dp_{n-2}+...+dp_{n-1} \times dp_{0}
$$
[详细题解见Leetcode](https://leetcode-cn.com/problems/unique-binary-search-trees/solution/jian-dan-yi-dong-de-dpjie-jue-si-lu-by-guo-bu-liao/)

> ## [410. 分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/)
* **动态规划**：**「将数组分割为 mm 段，求……」是动态规划题目常见的问法**，所以采用动态规划解题。`dp[i][j]`表示将前`i`个数分成 `j`段，可以将问题分解为更小的问题，假设前`k`个数，被分成 `j-1`段，剩余`k+1~i`被分为一段，那么我们只需要枚举`k`，而`k`的范围易得为 <small>$0\le k < i$</small>，当`k`为0时，表示前`i`个数被分为一段，那么状态转移方程就可以写为。并且在对数组分段中当<small>$j>i$</small>时，将长为`i`
$$
f[i][j]=\min _{k=0}^{i-1}\{\max (f[k][j-1], s u b(k+1, i))\}
$$
的数组分为`j`段是并不合法的，由于我们最终的答案是各段子数组和的最大值的最小值，所以当<small>$j>i$</small>时，将 $dp_{i,j}=+\infty$即可，由于我们需要保证最后一段分段的合法性，所以最后一定最少留一个数，所以`k`最多到前`i-1`个数。最后返回的结果是`dp[n][m]`
* **二分查找**：**「使……最大值尽可能小」是二分搜索题目常见的问法**。这题目的答案一定在$[max(nums), sum(nums)]$区间内，那么我们采用二分法，确定一个数字，使得最终分段的段数跟目标段数相等，且值最小。假设我们得到一个数作为数组分段的最大值，那么所有子数组的和都不能大于该值，我们遍历数组，在遍历的过程中累加元素，如果当前元素和大于该数，则`cnt++`表示又切分出一个子数组，
    * 如果切分出的子数组大于给定目标子数组数量，那么说明区间和的最大值给的较小，`low = mid + 1`;
    * 如果切分出的子数组小于等于给定目标子数组数量，那么说明区间和的最大值可能较大，`high = mid`;

> ## [85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)
<div align=center>
<img src="../Image/85.gif">
</div>

* **动态规划**：假设我们能够确认以当前格子对应的矩形的最大值，我们只需要确认，左边界 `left`，右边界 `right`，和高`height`，就可以计算出该矩形的面积
* 首先初始化三个数组`left`、`right`、`height`，其中`left`中填充`0`，`right`中填充`n`，`height`中填充`0`
    * `height`状态转移：如果矩阵当前值为`0`，高度为`0`，否则`height[i]++`
$$
height_i=\left\{
\begin{array}{rcl}
height_i+1      &     & matrix[i][j]==1\\
0    &     & matrix[i][j]==0
\end{array} \right.
$$
    * `left`状态转移：当前状态前的情况在未更新的`left`中都已经考虑过，所以只需要考虑当前位置是不是`0` 
$$
left_i=\left\{
\begin{array}{rcl}
max(current\_left, left_i)      &     & matrix[i][j]==1\\
0    &     & matrix[i][j]==0
\end{array} \right.
$$

    * `right`状态转移：与`left`相似，但是要从右边开始更新
$$
right_i=\left\{
\begin{array}{rcl}
min(current\_right, right_i)      &     & matrix[i][j]==1\\
n    &     & matrix[i][j]==0
\end{array} \right.
$$

* **栈**：我们可以将每一层的最大矩形转换成 [柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)中的问题，如果当前`matrix[i][j]=='1'`是，向上找`height`，最后结果写入数组中传入柱状图中最大的矩形对应的函数中，即可以得到每一层最大的矩形，同时在每层最大矩形更新的时候记录全局最大的矩形，可以得到矩阵中的最大矩形面积