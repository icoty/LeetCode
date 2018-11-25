#include "AllInclude.h"

class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            if(grid.size() < 1)
                return 0;
            int ret = 0;    // https://www.cnblogs.com/joannacode/p/6096561.html
            for(int i = 0; i < grid.size(); ++i)
            {
                for(int j = 0; j < grid[0].size(); ++j)
                {
                    if(1 == grid[i][j])
                    {
                        ret += 4;                   
                        if(i > 0 && 1 == grid[i - 1][j])
                            ret -= 1;
                        if(i < grid.size() - 1 && 1 == grid[i + 1][j])
                            ret -= 1;
                        if(j > 0 && 1 == grid[i][j - 1])
                            ret -= 1;
                        if(j < grid[0].size() - 1 && 1 == grid[i][j + 1])
                            ret -= 1;
                    }
                }
            }
            return ret;
        }
};
