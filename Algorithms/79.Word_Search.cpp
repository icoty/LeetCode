#include "AllInclude.h"

class Solution {
    public:
        bool bfs(vector<vector<char>>& board, vector<vector<bool>>& visit, string& word, int idx, int r, int c)
        {
            if(idx == word.size())
                return true;
            int m = board.size();
            int n = board[0].size();
            if(r < 0 || r >= m || c < 0 || c >= n || visit[r][c] || board[r][c] != word[idx])
                return false;
            visit[r][c] = true;
            bool next = bfs(board, visit, word, idx + 1, r + 1, c) || bfs(board, visit, word, idx + 1, r - 1, c) || bfs(board, visit, word, idx + 1, r, c + 1) || bfs(board, visit, word, idx + 1, r, c - 1);
            visit[r][c] = false;
            return next;
        }

        bool exist(vector<vector<char>>& board, string word) {
            if(board.size() < 1 || board[0].size() < 1)
                return false;
            int r = board.size();
            int c = board[0].size();
            vector<vector<bool>> visit(r, vector<bool>(c, false));
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(bfs(board, visit, word, 0, i, j))
                        return true;
                }
            }
            return false;
        }
};
