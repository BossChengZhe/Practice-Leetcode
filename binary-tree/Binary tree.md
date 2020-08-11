> ## [297.二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)
&emsp;&emsp;由于二叉树的遍历方式有很多，前序中序后序遍历，还有什么层次遍历，我是用的前序遍历得到的结果(应该是我的写法问题，成绩很差)
* 编码部分：我采用的是前序遍历，如果当前节点不为空，则将`node->val`填入字符串中，然后递归遍历左子树和右子树；如果当前节点为空，填入n，表示该节点为空。
* 解码部分：思路就是遍历的逆，如果读取字符串，得到当前`val`是`n`，则当前节点是空节点返回`NULL`，否则新建节点，并递归左子树和右子树。

> ## [108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)
&emsp;&emsp;建立二叉搜索树首先要明白二叉搜索树的原理，对于每个节点来说，左子树节点的值比当前值要小，右子树节点的值要比当前节点大。基于此条性质我们可以每次在建立一个新的二叉搜索树时，采用中值作为根节点，左半部分作为左子树节点的值递归，右半部分作为右子树的值递归建立，得到可能的二叉搜索树。

> ## [112.路径总和](https://leetcode-cn.com/problems/path-sum/)
&emsp;&emsp;递归解法，
* 如果当前节点左右孩子均为空，说明此节点是叶子节点，比较当前`num`值和叶子节点是否相等，如果相等的话，返回`true`，否则返回`false`；
* 如果当前节点为空，说明已经到达了叶子节点的左右孩子或者兄弟；
    * 如果是叶子节点的左右兄弟，那么没有在叶子节点返回，说明这条根到路径的和跟`num`不相等，所以返回`false`
    * 如果是叶子节点的左右兄弟，这条路径根本不符合条件，返回`false`
* 不属于以上两种情况，即中间节点，递归寻找左右子树；

> ## [95. 不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)
&emsp;&emsp;首先声明，本题中需要返回的是各个不同二叉搜索树的根节点，不需要对二叉树遍历，解题思路与 [不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)相同，循环遍历依次将每一个顶点设置为根节点，并且递归生成左子树和右子树

    注意在递归生成的过程中，如果遇到`l>r`的情况，应该返回`{NULL}`

> ## [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)
&emsp;&emsp;二叉树的中序遍历也是个老问题了，两种方法解决
* 递归法：这个代码最好理解也最好实现，不详细谈了
* 栈：cur指针时刻指向需要处理的节点
    * 如果当前节点不为空，则压入栈中，并改变cur指针指向其左节点
    * 如果当前节点为空，也代表空节点的中序遍历自动完成，无需压栈，这时候需要弹出栈顶的节点，保存栈顶节点的值，并更改cur指向其右子树，以完成右子树的中序遍历

> ## [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)
&emsp;&emsp;根据二叉搜索树的定义，所有的左子树只包含小于当前节点的数，右子树只包含大于当前节点的数，并且对于左右节点同样满足此特点的二叉树被称为二叉搜索树。
* **递归法**：由于二叉搜索树的特性，左子树的所有节点都不能大于该节点的值，所以设置上下界，如果子树所有节点满足要求，返回`true`，否则返回`false`
* **中序遍历**：二叉搜索树中序遍历是一个升序数组，所以只需要中序遍历同时记录当前节点是不是大于上一个节点就可以了。

> ## [99.恢复二叉搜索树](https://leetcode-cn.com/problems/recover-binary-search-tree/)
* 由于二叉搜索树中只有两个节点被错误的交换，由[验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)中的方法可以得到，二叉搜索树的中序遍历是有序的，在中序遍历的序列中找出逆序对，存储前驱和当前节点
    * 当只存储两个节点时，直接交换节点值
    * 当`res`中存储四个节点，则需要交换`res[0]`和`res[3]`的值，就可以恢复二叉搜索树。
* [Morris中序遍历](https://leetcode-cn.com/problems/recover-binary-search-tree/solution/hui-fu-er-cha-sou-suo-shu-by-leetcode-solution/)：这个看不懂**做个笔记**，可以实现空间复杂度为常数级的二叉树遍历算法。

> ## [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
&emsp;&emsp;经典问题层次遍历，利用队列实现层次遍历，下面是主体部分模板
```C++
queue<TreeNode *> q;
q.push(root);      // 首先将二叉树的根节点推入队列中
while(!q.empty())
{
    int q_size = q.size();  // 注意这里是固定队列的大小，在遍历的过程中队列大小会发生变化
    for(int i = 0; i < q_size; i++)
    {
        TreeNode *node = q.front();
        q.pop();
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}
```

> ## [103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)
&emsp;&emsp;层次遍历，设置一个`flag`，奇数层不变，偶数层翻转