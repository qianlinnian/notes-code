# 数据结构

#### 哈希表
> 哈希表（Hash Table）是一种数据结构，它通过一种被称为哈希函数（Hash Function）的特殊函数，将数据的键（Key）映射到一个数组中的特定位置（称为哈希值或索引）来实现高效的数据存储和查找。

哈希表的基本概念
 键值对（Key-Value Pair）

    哈希表以键值对的形式存储数据。
    键（Key）： 数据的唯一标识。    值（Value）： 与键相关联的数据。
    哈希函数（Hash Function）

    将键转换为数组中的索引值。
    哈希函数的目标是将键均匀地分布到数组的不同位置，减少冲突。
    
    数组（Bucket）
    哈希表的底层数据结构通常是一个数组，哈希函数会将键映射到数组中的某个位置。

#### 字符串函数
substr 函数的用法
复制
string substr(size_t pos = 0, size_t len = npos) const;
参数说明：

pos：起始位置（从 0 开始计数）。
len：要截取的长度。如果 len 超过了字符串的剩余长度，则会截取到字符串的末尾。
返回值：返回一个新的字符串，包含从 pos 开始、长度为 len 的子串。

#### 集合
集合的定义：  
    在计算机科学和编程中，集合（Set） 是一种数据结构，用于存储一组互不相同的元素，且通常不保证元素的顺序。它基于数学中的集合概念，并提供高效的插入、删除和查找操作。  
集合的特点：  
    无序性：  
    集合中的元素没有固定的顺序。  
    唯一性： 
    集合中的元素是唯一的，不能重复。  
    如果尝试插入已经存在的元素，集合会忽略该操作。   
    高效性：  
    集合通常使用哈希表或平衡二叉树实现，插入、删除和查找。  
操作：
1. 添加元素 ` insert() `  
将一个元素插入集合。如果元素已经存在，集合不会重复存储。  
2. 删除元素 ` find() `  
从集合中移除一个元素。如果元素不存在，操作不会报错。  
3. 查找元素 ` erase `  
检查一个元素是否在集合中。  
4. 集合运算
并集：将两个集合的所有元素合并，去重后形成一个新的集合。  
交集：返回两个集合中共同的元素。  
差集：返回一个集合中有但另一个集合中没有的元素。  
对称差：返回两个集合中不重叠的元素。  
例题：  
[学号：查找absent学生（hard） ](https://ac.nowcoder.com/acm/contest/20960/1022)

#### pair
pair 是一个简单的容器，可以将两个值（可能是不同类型）组合在一起。
它的主要成员是 first 和 second，分别存储两个值。
可以通过直接构造或 make_pair 创建 pair。  
pair 常用于返回多个值、存储键值对或排序辅助等场景。
```cpp
template <class T1, class T2>
struct pair {
    T1 first;  // 第一个元素
    T2 second; // 第二个元素
};
```


####  sort

```cpp
// 按自定义规则排序
    sort(nums.begin(), nums.end(), compare);
```

在 C++ 中，std::sort 是一个非常强大的标准库函数，它可以对容器中的元素进行排序。默认情况下，std::sort 会使用 升序排序，即通过 < 运算符比较两个元素的大小。如果需要自定义排序规则，可以通过传递一个 自定义比较函数 或 比较函数对象 来实现。

#### 排列

长度为 𝑛 的排列是由 1 ∼𝑛 这 𝑛 个整数、按任意顺序组成的数组，其中每个整数恰好出现一次。例如，{2,3,1,5,4}{2,3,1,5,4} 是一个长度为 5 的排列，而 {1,2,2}{1,2,2} 和 {1,3,4}{1,3,4} 都不是排列，因为前者存在重复元素，后者包含了超出范围的数。

#### 优先级队列

``` cpp
priority_queue<mymessages, vector<mymessages>, CompareRight>
priority_queue<
    mymessages,                // 第一个参数：存储的元素类型
    vector<mymessages>,        // 第二个参数：底层容器类型
    CompareRight               // 第三个参数：比较函数的类型
> pq;                         // pq 是优先队列的变量名
```
在优先级队列中重载比较运算符有两种主要方式：   
- 使用结构体重载运算符  
- 使用比较函数对象（仿函数）
```cpp
// 优先队列的比较函数
struct CompareRight {
    bool operator()(const mymessages& a, const mymessages& b) {
        return a.lr.second > b.lr.second;  // 小顶堆，按右端点排序
    }
};
```
在优先队列的比较函数中，operator() 的返回值决定了元素的优先级：

如果返回 true，表示第一个元素优先级低于第二个元素
如果返回 false，表示第一个元素优先级高于第二个元素

sort 和 priority_queue 的比较函数确实是相反的行为。

#### 线段树  
线段树是一种高效的数据结构，主要用于处理区间查询和修改操作。每个节点代表一个区间，父节点的区间是子节点区间的并集。   
基本特性：  
- 完全二叉树结构
- 每个节点维护一个区间[l, r]
- 空间复杂度：O(4N)
- 查询和修改的时间复杂度：O(logN)

#### map
map 是 C++ STL (标准模板库) 中的一个容器;    
`map<Key, Value> name;  // Key是键的类型，Value是值的类型`
存储键值对 (key-value pairs)
键必须唯一
默认按键的升序排序
内部实现通常是红黑树
```cpp
// 声明
map<string, int> m;
map<int, string> scores;

// 插入元素
m["apple"] = 1;       // 方式1
m.insert({"banana", 2}); // 方式2

// 访问元素
int value = m["apple"];  // 如果key不存在，会创建并返回默认值
int value2 = m.at("apple");  // 如果key不存在，会抛出异常

// 检查是否存在
if(m.count("apple")) { ... }  // 存在返回1，不存在返回0
if(m.find("apple") != m.end()) { ... }  // 另一种检查方式

// 删除元素
m.erase("apple");

// 获取大小
int size = m.size();

// 遍历
for(auto& pair : m) {
    cout << pair.first << ": " << pair.second << endl;
}
```
```cpp
map<int, int> m;

// 1. 访问不存在的键会创建它
m[100];  // 会创建键100，值为0

// 2. 安全的查找方式
auto it = m.find(100);
if(it != m.end()) {
    // 键存在
    cout << it->second;
}

// 3. 插入检查
auto [it, inserted] = m.insert({1, 10});
if(inserted) {
    cout << "插入成功";
}

// 4. 清空map
m.clear();

```

#### 线段树
线段树使用一种树状结构来存储一个连续区间的信息的数据结构。
采用了二分的概念。
左儿子=父节点*2  右儿子=父节点 *2+1
父节点=子节点/2；
最大深度为logn级别。
重点是维护什么
- 直接算区间修改之后要哪些量
- 子区间合并为大的区间需要什么量，维护什么。

#### ST表
这实际上是一种倍增的方法。
用一个二维数组f(i,j)即区间[i,i+2^j-1]（持续2^j个）区间中的最小值。
其中f[i,0]=a[i];
所以对于任意一组(i,j)
f(i,j)=min{f(i,j-1),f(i+2^(j-1),j-1)}来使用动态规划计算出来。


#### 二分法
单调函数求零点，查找某个元素。   
限定次数的循环(对于double)

#### vector
`nums.erase(nums.begin() + i)`
#### 主席树

#### bitset 
> bitset 是 C++ 标准库中的一个模板类，用于高效地存储和操作固定大小的二进制位集合。

> bitset 的特点:
    固定大小：bitset<N> 的大小在编译时确定，表示它可以存储最多 N 位。
    高效存储：bitset 使用位级存储，比普通数组节省内存（例如，bitset<9> 只需要 9 位，约等于 1 个字节）。
    快速操作：支持按位操作（如与、或、非），以及一些高级操作（如计数、翻转等）。    
    接口丰富：提供了易用的成员函数，比如 set、reset、test、count 等。

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    // 定义一个大小为9的bitset
    bitset<9> b;

    // 设置第3位为1（从右往左，第0位是最低位）
    b.set(2);
    cout << "After setting bit 2: " << b << endl; // 输出: 000000100

    // 测试第3位是否为1
    cout << "Bit 2 is set? " << b.test(2) << endl; // 输出: 1

    // 设置第5位为1
    b.set(4);
    cout << "After setting bit 4: " << b << endl; // 输出: 000010100

    // 统计有多少位是1
    cout << "Number of 1s: " << b.count() << endl; // 输出: 2

    // 重置第3位为0
    b.reset(2);
    cout << "After resetting bit 2: " << b << endl; // 输出: 000010000

    // 取反操作
    b.flip();
    cout << "After flipping bits: " << b << endl; // 输出: 111101111

    return 0;
}
```

