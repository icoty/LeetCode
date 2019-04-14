#include "AllIncude.h"

class Solution {
    public:
        int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
            int ret = 0;
            vector<int> row(grid.size(), 0), col(grid[0].size(), 0);
            for(auto i = 0; i < grid.size(); ++i){
                for(auto j = 0; j < grid[i].size(); ++j)
                    if(grid[i][j] > row[i])
                        row[i] = grid[i][j];
            }

            for(auto i = 0; i < grid[0].size(); ++i){
                for(auto j = 0; j < grid.size(); ++j)
                    if(grid[j][i] > col[i])
                        col[i] = grid[j][i];
            }

            for(auto i = 0; i < grid.size(); ++i)
                for(auto j = 0; j < grid[i].size(); ++j)
                    ret += min(row[i], col[j]) - grid[i][j];

            return ret;
        }
};
