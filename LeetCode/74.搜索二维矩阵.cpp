/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mymin=matrix[0][0];
        int m=matrix.size();
        int n=matrix[0].size();
        int mymax=matrix[m-1][n-1];
        if(target<mymin||target>mymax)
        {
            return false;
        }

        for(int i=0;i<m;i++)
        {
            if(target>matrix[i][n-1])
                continue;
            for(int j=0;j<n;j++)
            {
                if(target==matrix[i][j])
                    return true;
            }

        }
        return false;


        
    }
};
// @lc code=end

