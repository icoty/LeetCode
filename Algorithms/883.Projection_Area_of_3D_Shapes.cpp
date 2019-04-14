#include "AllInclude.h"

class Solution {
    public:
        int projectionArea(vector<vector<int>>& grid) {
            int sum = 0;
            for(int i = 0; i < grid.size(); ++i)
            {
                int colmax = 0;
                int rowmax = 0;
                for(int j = 0; j < grid[i].size(); ++j)
                {
                    if(grid[i][j] > colmax)
                        colmax = grid[i][j];
                    if(grid[j][i] > rowmax)
                        rowmax = grid[j][i];
                    if(0 != grid[i][j])
                        ++sum;
                }
                sum += colmax + rowmax;
            }
            return sum;
        }
};
