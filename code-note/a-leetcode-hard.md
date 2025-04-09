## *32.最长有效括号*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串长度
#### 题解一
> 结合题目，有 最长 这个字眼，可以考虑尝试使用 动态规划 进行分析。这是一个 最值型 动态规划的题目。
首先，我们定义一个 dp 数组，其中第 i 个元素表示以下标为 i 的字符结尾的最长有效子字符串的长度。
s[i]== ′ ( ′  :这时，s[i] 无法和其之前的元素组成有效的括号对，所以，dp[i]=0
s[i]== ′ ) ′  :这时，需要看其前面对元素来判断是否有有效括号对。
    
- 情况1:  s[i−1]== ′ ( ′ 
    即 s[i] 和 s[i−1] 组成一对有效括号，有效括号长度新增长度2，i位置对最长有效括号长度为 其之前2个位置的最长括号长度加上当前位置新增的2，我们无需知道i−2位置对字符是否可以组成有效括号对。
    那么有：dp[i]=dp[i−2]+2 

- 情况2：s[i−1]== ′ ) ′
    这种情况下，如果前面有和s[i]组成有效括号对的字符，即形如 ((....))，这样的话，就要求s[i−1]位置必然是有效的括号对，否则s[i]无法和前面对字符组成有效括号对。

    这时，我们只需要找到和s[i]配对对位置，并判断其是否是 ( 即可。和其配对对位置为：i−dp[i−1]−1。

    如果：s[i−dp[i−1]−1]== ′ ( ′  :  
    有效括号长度新增长度 2，i 位置对最长有效括号长度为 i-1位置的最长括号长度加上当前位置新增的 2，那么有：
    dp[i]=dp[i−1]+2
- 值得注意的是，i−dp[i−1]−1 和 i 组成了有效括号对，这将是一段独立的有效括号序列，如果之前的子序列是形如 (...) 这种序列，那么当前位置的最长有效括号长度还需要加上这一段。所以：
- dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2

 #### 题解二
>   始终保持栈底元素为当前已经遍历过的元素中「最后一个没有被匹配的右括号的下标」，这样的做法主要是考虑了边界条件的处理，栈里其他元素维护左括号的下标

+ 对于遇到的每个 ‘(’ ，我们将它的下标放入栈中
对于遇到的每个 ‘)’ ，我们先弹出栈顶元素表示匹配了当前右括号：
+ 如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
+ 如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
 

 ## *33. 搜索旋转排序数组*
 > 整数数组 nums 按升序排列，数组中的值 互不相同 。
    在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
    给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
    你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

## *37.解数独*
> 如题
    位运算优化。<bitset>
```cpp
class Solution {
public:
    // 获取在位置(x,y)可以填入的所有可能数字
    // 返回一个bitset，其中为1的位表示该数字可以填入
    bitset<9> getPossibleStatus(int x, int y)
    {
        // 对行、列、3x3宫格中已使用的数字进行按位或运算，然后取反
        // 结果中为1的位表示该位置可以填入的数字(0-8对应数字1-9)
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    // 使用启发式方法找到下一个要填的位置
    // 策略是找出可选数字最少的空格，这样可以减少搜索分支
    vector<int> getNext(vector<vector<char>>& board)
    {
        vector<int> ret;  // 存储找到的位置坐标 [i, j]
        int minCnt = 10;  // 初始化为一个不可能的大值，因为最多只有9种可能
        
        // 遍历整个数独板
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;  // 跳过已填充的格子
                
                // 获取当前空格的可能数字
                auto cur = getPossibleStatus(i, j);
                
                // 如果可能的数字数量不少于当前最小值，则跳过
                if (cur.count() >= minCnt) continue;
                //cur.count() 计算了 cur 中值为 1 的位的数量，也就是可以填入位置 (i, j) 的数字的数量
                
                // 更新最少可能性的位置和计数
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;  // 返回可能性最少的空格位置
    }

    // 标记或取消标记在位置(x,y)填入数字n
    // fillFlag为true表示填入，false表示取消
    void fillNum(int x, int y, int n, bool fillFlag)
    {
        // 更新行、列、3x3宫格中数字n的使用状态
        rows[x][n] = (fillFlag) ? 1 : 0;
        cols[y][n] = (fillFlag) ? 1 : 0;
        cells[x/3][y/3][n] = (fillFlag) ? 1: 0;
    }
    
    // 深度优先搜索解决数独
    // cnt表示剩余需要填充的空格数量
    bool dfs(vector<vector<char>>& board, int cnt)
    {
        // 如果没有空格需要填充，说明找到解了
        if (cnt == 0) return true;

        // 获取下一个要填充的位置
        auto next = getNext(board);
        
        // 获取该位置所有可能的数字
        auto bits = getPossibleStatus(next[0], next[1]);
        
        // 尝试每一个可能的数字
        for (int n = 0; n < bits.size(); n++)
        {
            // 如果当前数字不可用(对应位为0)，则跳过
            if (!bits.test(n)) continue;
            
            // 标记使用该数字
            fillNum(next[0], next[1], n, true);
            
            // 在数独板上填入该数字(注意+1是因为数独中数字从1开始)
            board[next[0]][next[1]] = n + '1';
            
            // 递归解决剩余的空格，如果找到解则返回true
            if (dfs(board, cnt - 1)) return true;
            
            // 如果没找到解，回溯：恢复空格并取消标记
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        // 尝试了所有可能性都没找到解，返回false
        return false;
    }

    // 主函数：解决数独问题
    void solveSudoku(vector<vector<char>>& board) 
    {
        // 初始化数据结构
        // 每行、每列使用一个bitset<9>记录已使用的数字
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        // 每个3x3宫格使用一个bitset<9>记录已使用的数字
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;  // 记录空格数量
        
        // 遍历数独板，初始化状态
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // 统计空格数量
                cnt += (board[i][j] == '.');
                
                // 跳过空格
                if (board[i][j] == '.') continue;
                
                // 计算数字的索引(0-8)
                int n = board[i][j] - '1';
                
                // 使用位运算标记该数字已在对应行、列、宫格中使用
                // (1 << n)创建一个只有第n位为1的位掩码，然后与当前状态按位或
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        
        // 开始DFS求解
        dfs(board, cnt);
    }

private:
    // 记录每行已使用的数字
    vector<bitset<9>> rows;
    // 记录每列已使用的数字
    vector<bitset<9>> cols;
    // 记录每个3x3宫格已使用的数字
    vector<vector<bitset<9>>> cells;
};

```

## **