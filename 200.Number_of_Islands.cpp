#include "AllInclude.h"

class Solution {
    public:
        void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int r, int c)
        {
            if(r < 0 || r >= grid.size())
                return;
            if(c < 0 || c >= grid[0].size())
                return;
            if('0' == grid[r][c] || visit[r][c])
                return;
            visit[r][c] = true;
            dfs(grid, visit, r - 1 , c);
            dfs(grid, visit, r + 1 , c);
            dfs(grid, visit, r , c + 1);
            dfs(grid, visit, r , c - 1);
        }

        int numIslands(vector<vector<char>>& grid) {
            if(grid.size() < 1 || grid[0].size() < 1)
                return 0;
            int r = grid.size();
            int c = grid[0].size();
            int ret = 0;
            vector<vector<bool>> visit(r, vector<bool>(c, false));
            for(int i = 0; i < r; ++i)
            {
                for(int j = 0; j < c; ++j)
                {
                    if('1' ==  grid[i][j] && !visit[i][j]){
                        dfs(grid, visit, i, j);
                        ++ret;
                    }
                }
            }
            return ret;
        }
};
