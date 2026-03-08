/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution {
public:
    string toGoatLatin(string sentence) {
        // 1. 定义元音集合，方便快速查找
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        stringstream ss(sentence); // 将句子转为流，方便按空格提取单词
        string word, res;
        int cnt = 1; // 记录单词索引

        while (ss >> word) {
            // 如果不是第一个单词，先补一个空格
            if (cnt > 1) res += " ";

            // 处理规则 1 & 2：元音 vs 辅音
            if (vowels.count(word[0])) {
                res += word + "ma";
            } else {
                // 辅音：取 [1, n-1] 部分 + [0] 位置字符 + "ma"
                res += word.substr(1) + word[0] + "ma";
            }

            // 处理规则 3：添加对应数量的 'a'
            res.append(cnt, 'a');
            
            cnt++;
        }
        
        return res;
    }
};
// @lc code=end

