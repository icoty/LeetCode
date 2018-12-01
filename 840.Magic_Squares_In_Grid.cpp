#include "AllInclude.h"

class Solution {
    public:
        bool isOne2Nine(int num)
        {
            return  num >= 1 && num <= 9;   // 数字必须是1~9
        }
        bool isMagicSquares(vector<vector<int>>& g, int row, int col)
        {
            if(15 != g[row][col] + g[row+1][col+1] + g[row+2][col+2])
                return false;
            if(15 != g[row+2][col] + g[row+1][col+1] + g[row][col+2])
                return false;

            for(int i = row; i < row + 3; ++i)
            {
                if(!isOne2Nine(g[i][col]) || !isOne2Nine(g[i][col+1])|| !isOne2Nine(g[i][col+2]))
                    return false;
                if(15 != g[i][col] + g[i][col+1] + g[i][col+2])
                    return false;
            }

            for(int i = col; i < col + 3; ++i)
            {
                if(!isOne2Nine(g[row][i]) || !isOne2Nine(g[row+1][i])|| !isOne2Nine(g[row+2][i]))
                    return false;
                if(15 != g[row][i] + g[row+1][i] + g[row+2][i])
                    return false;
            }

            return true;
        }

        int numMagicSquaresInside(vector<vector<int>>& grid) {
            if(grid.size() < 3 || grid[0].size() < 3)
                return 0;
            int ret = 0;

            for(int i = 0; i < grid.size() - 2; ++i)
            {
                for(int j = 0; j < grid[0].size() - 2; ++j)
                {
                    isMagicSquares(grid, i, j) ? ++ret : 0;
                }
            }
            return ret;
        }
};
