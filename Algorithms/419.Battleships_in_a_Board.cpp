#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/5979207.html
        int countBattleships(vector<vector<char>>& board) {
            if (board.empty() || board[0].empty()) return 0;
            int res = 0, m = board.size(), n = board[0].size();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) continue;
                    ++res;
                }
            }
            return res;
        }
};
