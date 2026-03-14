/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
 
    void backtrack(vector<int>& nums, int start) {
        res.push_back(path); // 每个节点都是一个子集
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back(); // 撤销选择
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtrack(nums, 0);
        return res;
    }
};
// @lc code=end

