#### *049.求根节点到叶子节点的数字之和*
方法一：深度优先搜索
思路与算法

深度优先搜索是很直观的做法。从根节点开始，遍历每个节点，如果遇到叶子节点，则将叶子节点对应的数字加到数字之和。如果当前节点不是叶子节点，则计算其子节点对应的数字，然后对子节点递归遍历。
 方法二：广度优先搜索
思路与算法

使用广度优先搜索，需要维护两个队列，分别存储节点和节点对应的数字。

初始时，将根节点和根节点的值分别加入两个队列。每次从两个队列分别取出一个节点和一个数字，进行如下操作：

如果当前节点是叶子节点，则将该节点对应的数字加到数字之和；

如果当前节点不是叶子节点，则获得当前节点的非空子节点，并根据当前节点对应的数字和子节点的值计算子节点对应的数字，然后将子节点和子节点对应的数字分别加入两个队列。

搜索结束后，即可得到所有叶子节点对应的数字之和。

#### *050.路径总和*
思路：前缀和
解题过程

维护当前和，记录过去和的数量，当差值出现target代表出现和为target带路径



 #### *22.括号生成*
方法一：暴力法
思路:
    我们可以生成所有 2^n个 ‘(’ 和 ‘)’ 字符构成的序列，然后我们检查每一个是否有效即可。

#### *3488.距离最小相等元素查询*

> 看示例 1，所有 1 的下标列表是 p=[0,2,4]。
    由于 nums 是循环数组：
    在下标列表前面添加 4−n=−3，相当于认为在 −3 下标处也有一个 1。   
    在下标列表末尾添加 0+n=7，相当于认为在 7 下标处也有一个 1。
        p[j−1] 就是在 i 左边的最近位置。
        p[j+1] 就是在 i 右边的最近位置。
        两个距离取最小值，答案为    min(i−p[j−1],p[j+1]−i)
    如果 nums[i] 在 nums 中只出现了一次，那么答案为 −1。
```cpp
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> indices;        //哈希表<int,vector<int>> 用于存储数字和坐标
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);              //输入num[i] 的当前的坐标
        }

        int n = nums.size();                            //数组大小
        for (auto& [_, p] : indices) {
            // 前后各加一个哨兵
            int i0 = p[0];                              //保存第一个元素
            p.insert(p.begin(), p.back() - n);          //在首位插入哨兵，哨兵值为末位置值-n
            p.push_back(i0 + n);                        //在末尾插入哨兵，哨兵值为i0+n
        }
        //哨兵值为循环数组坐标

        for (int& i : queries) {                        // 注意这里是引用
            auto& p = indices[nums[i]];                 // 这里应该也是引用
            if (p.size() == 3) {                        //判断大小 如果是3 则本数字在数组中只出现了1次，所以没有重复的数字。标记为-1；  答案直接存储在了queries里面，节省了存储空间。
                i = -1;
            } else {
                int j = ranges::lower_bound(p, i) - p.begin();//这行代码在数组p中查找第一个大于等于i的元素位置，并返回该位置的索引。
                i = min(i - p[j - 1], p[j + 1] - i);    //取最小值
            }
        }
        return queries;         //询问变为答案数组。
    }
};
```
#### *38.外观数列*
-  递归 根据 n-1 的string数列，求出n的数列

#### *组合总和2*
> 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
  candidates 中的每个数字在每个组合中只能使用 一次 。
  注意：解集不能包含重复的组合。  

- 递归回溯


#### *235.二叉搜索树的最近公共祖先*
> 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

==两次遍历==
- 注意到题目中给出的是一棵「二叉搜索树」，因此我们可以快速地找出树中的某个节点以及从根节点到该节点的路径
- 我们可以在路径中找到，最终的相同的深度。

==一次遍历==
- 我们从根节点开始遍历；
- 如果当前节点的值大于 p 和 q 的值，说明 p 和 q 应该在当前节点的左子树，因此将当前节点移动到它的左子节点；
- 如果当前节点的值小于 p 和 q 的值，说明 p 和 q 应该在当前节点的右子树，因此将当前节点移动到它的右子节点；
- 如果当前节点的值不满足上述两条要求，那么说明当前节点就是「分岔点」。此时，p 和 q 要么在当前节点的不同的子树中，要么其中一个就是当前节点。

#### *236.二叉树的最近公共祖先*

==题解一：递归==
![题解一](image-13.png)
==题解二：存储父节点==
![题解二](image-14.png)
```cpp
class Solution {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root){
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
};

```