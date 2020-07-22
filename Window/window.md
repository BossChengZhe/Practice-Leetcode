> ## [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)
* 暴力算法：从头开始依次以第`i`个位置的字符作为子串的开始，扫描直到所有可能字符被扫描，在扫描的过程中会得到最短的字符串长度以及对应的起始位置。
* 滑动窗口法：双指针的进阶玩法，以题目给定输入为示例，演示双指针过程。
<div align=center>
<img src="../Image/76.gif">
</div>