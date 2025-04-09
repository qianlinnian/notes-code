# STL 和基本数据结构
 
## 容器
### vector
#### 定义
略去
#### 常用操作
1. push_back();
2. size()
3. empty()
4. a.insert(a.befgin()+i,k)  在第i个元素前面加上k
5. a.insert(a.end(),10,5) 在a的末尾插入10个5
6. a.pop_back()  删除末尾元素
7. a.erase(a.begin()+i,a.begin()+j);  删除区间[i,j-1] 的元素
8. a.erase(a.begin()+i);  删除第元素`a[i]`
9. resize()
10. clear() 清空
11. reverse() 反转函数
12. sort 排序 默认从小到大

### 栈和 stack
#### 定义 `#include<stack>`
#### 操作
1. push()
2. top()
3. pop()
4. size()
5. empty()

### 队列 和 queue
#### 定义
略去
#### 操作
1. push         // 入队
2. front        // 取得首元素
3. pop          // 删除首元素
4. back         // 队尾元素
5. size         //元素个数
6. empty        // 检查是否为空

### 优先队列和 priority queue
#### 定义
优先级最高的显出对 是队列与排序的结合
总的时间复杂度为
$O(n\log_{2}n)$

#### 操作
1. top
2. pop
3. push

### 链表和LIST
#### 定义
数据结构的双向链表 可以高效率的在任意地方删除和插入
#### 操作
同上

### set
#### 定义
用二叉搜索树实现 集合中的每个元素只出现一次，且排好序 访问的时间复杂度是 $O(log_{2}n)$
#### 操作
1. insert(item)  把item放入set
2. erase (item)  删除元素item