/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mymin=10001,mymax=-1;
        int s=nums.size();
        for(int c:nums){
            if(mymin>c) mymin=c;
            if(mymax<c) mymax=c;
        }
        return max(0, (mymax - mymin) - 2*k);
    }
};
// @lc code=end

