/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len=s.length();
        vector<int> poss;
        for(int i=0;i<len;i++){
            if(isalpha(s[i]))
            {
                poss.push_back(i);
            }            
        }
        int size=poss.size();
        for(int i=0;i<size/2;i++)
        {
            swap(s[poss[i]],s[poss[size-1-i]]);
        }
        return s;

    }
};
// @lc code=end

