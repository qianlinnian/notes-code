# include<iostream>
# include<vector>
# include<string>
using namespace std;
const long long Mode=998244353;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    /*
     * 状态定义：
     * dp[l][r] 表示子串 s[l..r] 中非空回文子序列的数量。
     * 不同的下标选择视为不同方案。
     */
    vector<vector<int>> dp(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        // 单个字符本身就是一个回文子序列。
        dp[i][i]=1;
    }
    // 大区间依赖小区间，因此按照区间长度从小到大计算。
    for(int len=2;len<=n;len++)
    {
        for(int l=0;l+len-1<n;l++)
        {
            int r=l+len-1;
            if(s[l]==s[r])
            {
                /*
                 * 先考虑不同时使用两个端点的方案：
                 * A = dp[l+1][r]，B = dp[l][r-1]，
                 * C = dp[l+1][r-1] 是 A、B 重复计算的交集，
                 * 因此这部分共有 A + B - C 种。
                 *
                 * 因为两端字符相同，还能同时选择两个端点：
                 * 两端包住内部回文子序列有 C 种，
                 * 只选择两个端点还有 1 种，共 C + 1 种。
                 *
                 * 合并后：(A + B - C) + (C + 1) = A + B + 1。
                 * 所以这里并非忘记减 C，而是减去的 C 与新增的 C 抵消了。
                 */
                dp[l][r]=(dp[l+1][r]+dp[l][r-1]+1)%Mode;
            }
            else
            {
                /*
                 * dp[l+1][r] 中的方案不选左端点，
                 * dp[l][r-1] 中的方案不选右端点。
                 * 两端都不选的方案在二者中各出现一次，共计算了两次，
                 * 它们正是 dp[l+1][r-1]，所以需要减去一次。
                 *
                 * 两端字符不同时，不可能同时选择两端构成回文子序列。
                 */
                dp[l][r]=(dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+Mode)%Mode;
            }
        }
    }

    /*
     * dp[0][n-1] 对应整个字符串，已经包含所有回文子序列。
     * 不能累加所有 dp[l][r]，否则同一方案会在多个区间中重复统计。
     */
    cout<<dp[0][n-1]<<endl;

    return 0;
}
