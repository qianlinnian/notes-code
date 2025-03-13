## Fundamentals of the Analysis of Algorithm Efficiency
- Algorithm analysis framework          算法分析框架
- Asymptotic notations                  渐进符号
- Analysis of non-recursive algorithms  非递归算法分析
- Analysis of recursive algorithms      递归算法分析

### Algorithm analysis framework          算法分析框架
  1. measuring running time                                          运行时间
  2. measuring an input's size                                       输入规模
  3. orders of growth(of thr algorithm's efficiency function)        增长阶
  4. worst-base ,best-case and average-case efficiency               最坏，最好，平均情况效率

#### Units for Measuring Running Time
   1. 根据计算机的速度，程序的质量 决定测量运行时间单位 分钟/秒   the speed of the computer the quality of programing
   2. 计算每个元素的执行次数     是困难且没有必要的
   3. solution： 计算最基本的操作的执行次数
   4. Basic operation :the operation that contributes the most to the total running time 一般是最耗时的操作
#### Measuring Input Size
   1. 效率受到输入规模的影响
#### Theoretical Analysis of Time Efficiency
#### Order of growth
    1 - log n - n - n log n - n^2 - n^3 - 2^n - n!
#### worst-base ,best-case and average-case efficiency
$Tavg(n)=cigema（p(I)T(I)）    Tworst(n) Tbest(n)$