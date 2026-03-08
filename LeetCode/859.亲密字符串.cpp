/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s==goal){
            vector<int> cnt(26,0);
            for(char c:s) cnt[c-'a']++;
            for(int i=0;i<26;i++){
                if(cnt[i]>1) return true;
            }
            return false;
        }
        int i=s.length()-1,j=goal.length()-1;
        if(i!=j) return false;
        vector<int> pos;
        while(i>=0 && j>=0){
            if(s[i]!=goal[j]) pos.push_back(i);
            i--;
            j--;
        }
        if(pos.size()!=2) return false;
        return s[pos[0]]==goal[pos[1]] && s[pos[1]]==goal[pos[0]];
    }
};
// @lc code=end

