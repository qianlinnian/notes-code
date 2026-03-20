/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int size=nums.size();
        int pos=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]%2==0){
                swap(nums[i],nums[pos]);
                pos++;
            }
            
        }

        return nums;
    }
};
// @lc code=end

