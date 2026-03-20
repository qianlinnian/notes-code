/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int size=deck.size();
        unordered_map<int,int> map;
        for(int n:deck)
        {
            map[n]++;
        }
        int x=size;
        for(auto p:map)
        {
            x=gcd(x,p.second);
        }
        if(x<2)
            return false;
        else 
            return true;
    }
};
// @lc code=end

