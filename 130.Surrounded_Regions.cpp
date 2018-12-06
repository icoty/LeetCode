#include "AllInclude.h"

class Solution {
    public:
        void dfs(vector<vector<char>>& board, int i, int j, int& r, int& c)
        {
            if('O' == board[i][j]){
                board[i][j] = '#';
                if(i + 1 < r - 1)
                    dfs(board, i + 1, j, r, c);
                if(i - 1 > 0)
                    dfs(board, i - 1, j, r, c);
                if(j + 1 < c - 1)
                    dfs(board, i, j + 1, r, c);
                if(j - 1 > 0)
                    dfs(board, i, j - 1, r, c);                
            }
        }

        void solve(vector<vector<char>>& board) {
            int r = board.size();
            if(r <= 2)
                return;
            int c = board[0].size();
            if(c <= 2)
                return;

            int i = 0;
            int j = 0;
            for(; i < r -1; ++i)        // 0 列
                dfs(board, i, j, r, c);
            for(; j < c - 1; ++j)
                dfs(board, i, j, r, c); // r - 1 行
            for(; i > 0; --i)
                dfs(board, i, j, r, c); // c - 1 列
            for(; j > 0; --j)
                dfs(board, i, j, r, c); // 0 行

            for(i = 0; i < r; ++i)
            {
                for(j = 0; j < c; ++j)
                {
                    if(board[i][j] == 'O')
                        board[i][j] = 'X';

                    if(board[i][j] == '#')
                        board[i][j] = 'O';
                }
            }
        }
};


