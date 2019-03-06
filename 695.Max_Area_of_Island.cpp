#include "AllInclude.h"

class Solution {
    public:
        int dfs(vector<vector<int>>& grid, int i, int j){
            if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
                return 0;

            int cnt = 0;
            if(grid[i][j] == 1){
                ++cnt;
                grid[i][j] = 0;

                cnt += dfs(grid, i - 1, j);
                cnt += dfs(grid, i + 1, j);
                cnt += dfs(grid, i, j - 1);
                cnt += dfs(grid, i, j + 1);
            }
            return cnt;
        }

        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ret = 0;
            for(int i = 0; i < grid.size(); ++i){
                for(int j = 0; j < grid[0].size(); ++j){
                    if(grid[i][j] == 1)
                        ret = max(ret, dfs(grid, i, j));
                }
            }
            return ret;
        }
};
