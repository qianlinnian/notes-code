/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int idx, vector<vector<bool>>& visited) {
        if (board[x][y] != word[idx]) return false;
        if (idx == word.size() - 1) return true;
        visited[x][y] = true;
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int d = 0; d < 4; ++d) {
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visited[nx][ny]) {
                if (dfs(board, word, nx, ny, idx + 1, visited)) return true;
            }
        }
        visited[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0, visited)) return true;
            }
        }
        return false;
    }
};
// @lc code=end

