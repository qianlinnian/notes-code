## Introduction
1. 算法的定义：
    在有限的时间内对问题求解的一个清晰的指令序列。算法的每个输入确定了该算法求解问题的一个实例。
     数据结构很重要
2. 算法的属性 Properties if algorithms
   输入：Input 
   输出：Output
   确定性：Tangibility
   有限性：Finiteness
   可行性：Feasibility

3. gcd（最大公约数） 的三种算法
   1. `gcd(m,n)=gcd(n,m mod n)`
   2.  从`t=min(n,m)`开始进行遍历，直到`m mod t==0 && n mod t ==0`为止。
   3.  查找m,n 的最基本的公约数，并筛选出相同的公约数进行计算。（要注意数量）
   
4. 伪代码：
   1. Algorithm name( variables)
   2. 算法的目的，解决的问题
   3. 输入和输出的变量的描述
   4. 用<-表示赋值

5. 算法 vs 程序
   1. 相同点：指令的有限序列。
   2. 不同点：
        - 算法是 自然语言 伪代码 流程图
        - 程序是 特定的编程语言可以在某些特定的机器上执行

        - 算法是有限的步骤
        - 程序可以无限的执行

        - 算法是一步一步地实现
        - 程序是基于算法的代码实现
    3. Algorithm + data structure = program
6. 