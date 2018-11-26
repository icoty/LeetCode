#include "AllInclude.h"

class Solution {
    public:
        int surfaceArea(vector<vector<int>>& grid) {
            int sum = 0;
            for(int i = 0; i < grid.size(); ++i)
                for(int j = 0; j < grid[0].size(); ++j)
                {
                    sum += grid[i][j] ? 4 * grid[i][j] + 2 : 0;
                    if(i > 0 && grid[i - 1][j] > 0)
                        sum -= min(grid[i][j], grid[i - 1][j]);
                    if(i < grid.size() - 1 && grid[i + 1][j])
                        sum -= min(grid[i][j], grid[i + 1][j]);
                    if(j > 0 && grid[i][j - 1] > 0)
                        sum -= min(grid[i][j], grid[i][j - 1]);
                    if(j < grid[0].size() - 1 && grid[i][j + 1] > 0)
                        sum -= min(grid[i][j], grid[i][j + 1]);              
                }
            return sum;
        }
};
