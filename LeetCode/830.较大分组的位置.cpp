/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            int j=i;
            while(j<len&&s[j]==s[i])
                j++;
            if(j-i>=3){
                res.push_back({i,j-1});
            }
            i=j-1;
        }
        return res;
    }
};
// @lc code=end

