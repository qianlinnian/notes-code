/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int size=nums.size();
        int o=0,j=1;
        while(o<size&& j<size)
        {
            while(o<size && nums[o]%2==0)
            {
                o+=2;
            }
            while(j<size && nums[j]%2==1)
            {
                j+=2;
            }
            if(o>=size || j>=size) break;
            swap(nums[o],nums[j]);
        }
        return nums;
    }
};
// @lc code=end

