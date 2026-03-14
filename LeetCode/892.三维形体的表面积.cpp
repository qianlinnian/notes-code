/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution {
public:

    int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    res+=6*grid[i][j]-2*(grid[i][j]-1);
                if(i>0) res-=2*min(grid[i][j],grid[i-1][j]);
                if(j>0) res-=2*min(grid[i][j],grid[i][j-1]);
            }
        }
        return res;
    }
};
// @lc code=end

