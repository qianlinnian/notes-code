/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> cnt;
        stringstream iss1(s1), iss2(s2);
        string word;
        while (iss1 >> word) cnt[word]++;
        while (iss2 >> word) cnt[word]++;
        vector<string> res;
        for (auto &kv : cnt) {
            if (kv.second == 1) res.push_back(kv.first);
        }
        return res;
    }
};
// @lc code=end

