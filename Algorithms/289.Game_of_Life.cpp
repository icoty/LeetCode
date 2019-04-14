#include "AllInclude.h"

/*状态0:死细胞转为死细胞; 状态1:活细胞转为活细胞; 状态2:活细胞转为死细胞; 状态3:死细胞转为活细胞*/
class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/4854466.html
        void gameOfLife(vector<vector<int>>& board) {
            int r = board.size();
            int c = 0 == r ? 0 : board[0].size();

            int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1}; // 周围8个点的下标在当前点(i,j)下的偏移
            int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    int cnt = 0;
                    for(int k = 0; k < 8; ++k){
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if(x >= 0 && x < r && y >=0 && y < c && (1 == board[x][y] || 2 == board[x][y]))
                            ++cnt;
                    }
                    if(1 == board[i][j] && (cnt > 3 || cnt < 2))   // 遍历(i,j)仅一次
                        board[i][j] = 2;
                    else if(0 == board[i][j] && 3 == cnt)
                        board[i][j] = 3;                
                }
            }

            for(int i = 0; i < r; ++i)
                for(int j = 0; j < c; ++j)
                    board[i][j] %= 2;
        }
};
