/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int zs=0,xs=0,ys=0;
        vector<int> xl(n,0),yl(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0)
                    zs++;
                if(grid[i][j]>xl[i])
                    xl[i]=grid[i][j];
                if(grid[i][j]>yl[j])
                    yl[j]=grid[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            xs+=xl[i];
            ys+=yl[i];
        }
        return zs+xs+ys;

    }
};
// @lc code=end

