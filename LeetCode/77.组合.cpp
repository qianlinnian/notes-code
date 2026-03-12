/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<int> num;
    vector<vector<int>> res;
    void make(int s,int n,int k)
    {
        if(num.size()==k)
            res.push_back(num);
        for(int i=s+1;i<=n;i++)
        {
            num.push_back(i);
            make(i,n,k);
            num.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
       for(int i=1;i<=n;i++)
       {
            num.push_back(i);
            make(i,n,k);
            num.pop_back();
       } 
       return res;

    }
};
// @lc code=end

