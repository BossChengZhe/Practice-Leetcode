> ## [48.旋转图像](https://leetcode-cn.com/problems/rotate-image/)
&emsp;&emsp;模拟一遍程序实际运行的过程，我们就可以知道转换的规律，并且旋转元素的周期是4，即四个元素后回到
$$matrix(i,j)\longrightarrow matrix(j, matrix_{size}-i-1)$$
原点，如下图所示。那么我们就可以直接得到方法，就是从内层往外层扩散，直至最外层循环结束。一个旋转周
<div align=center>
<img src="../Image/48.png">
</div>
期，我们采用一个4维数组维护当前数，保证交换正确性，根据规律依次改变交换目标的行列值，最后结束一次旋转周期。

> ## [1025. 除数博弈](https://leetcode-cn.com/problems/divisor-game/)
* 分析法：
    * 1：Alice没得选择，输了
    * 2：Alice选择1，Bob没有选择，Alice赢
    * 3：Alice选择1，根据上一条，Bob赢
    * 4：Alice可能选择1或者2，由于游戏双方都是以最佳状态参与游戏，即尽可能让自己赢，所以Alice选择1，那么根据上一条，Alice赢
    最终的结果是`return N % 2 == 0`
* 递推法：对于任意的 <small>$N \ge 1$</small>，只要存在一个数 <small>$i$</small>，使得 <small>$N-i$</small>可以让Alice胜利，那么该数就是可以让Alice胜利的数。