/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> count(m,vector<int>(n,0));
        count[0][0]=grid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    continue;
                }
                else if (i==0)
                {
                    count[i][j]=count[i][j-1]+grid[i][j];
                }
                else if(j==0)
                {
                    count[i][j]=count[i-1][j]+grid[i][j];
                }
                else
                {
                    count[i][j]=min(count[i-1][j],count[i][j-1])+grid[i][j];
                }
            }
        }
        return count[m-1][n-1];
    }
};
// @lc code=end

