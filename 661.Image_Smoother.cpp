#include "AllInclude.h"

// https://www.cnblogs.com/jimmycheng/p/7697511.html
class Solution {
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
            int row = M.size();
            int col = M[0].size();
            vector<vector<int>> ret(row, vector<int>(col));

            for(int i = 0; i < row; ++i)
            {
                for(int j = 0; j < col; ++j)
                {
                    int line = 0;
                    int cnt = 0;
                    for(int x = max(0, i - 1); x <= min(row - 1, 1 + i); ++x)
                    {
                        for(int y = max(0, j - 1); y <= min(col - 1, 1 + j); ++y)
                        {
                            line += M[x][y];
                            ++cnt;
                        }
                    }
                    ret[i][j] = line / cnt;
                }
            }
            return ret;
        }
};
