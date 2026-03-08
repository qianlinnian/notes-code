/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<vector<int>> result;
        for(int i=0;i<m;i++){
            int n=matrix[i].size();
            for(int j=0;j<n;j++){
                if(i==0){
                    vector<int> temp;
                    temp.push_back(matrix[i][j]);
                    result.push_back(temp);
                }
                else{
                    result[j].push_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};
// @lc code=end

