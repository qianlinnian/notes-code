/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> count(3,0);
        int size=bills.size();
        for(int i=0;i<size;i++){
            if(bills[i]==5)
            {
                count[0]++;
            }
            else if(bills[i]==10)
            {
                if(count[0]>0)
                {
                    count[0]--;
                    count[1]++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(count[1]>0&&count[0]>0)
                {
                    count[1]--;
                    count[0]--;
                    count[2]++;
                }
                else if(count[0]>2)
                {
                    count[0]-=3;
                    count[2]++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

