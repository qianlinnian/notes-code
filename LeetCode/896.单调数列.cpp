/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
public:
    bool isup(vector<int> &nums){
        int size=nums.size();
        for(int i=0;i+1<size;i++)
        {
            if(nums[i]>nums[i+1])
                return false;
        }
        return true;
    }
    bool isdown(vector<int> &nums){
        int size=nums.size();
        for(int i=0;i+1<size;i++)
        {
            if(nums[i]<nums[i+1])
                return false;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        if(isup(nums)||isdown(nums))
            return true;
        return false;
    }
};
// @lc code=end

