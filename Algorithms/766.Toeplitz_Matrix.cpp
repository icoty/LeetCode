#include "AllInclude.h"

class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            if(matrix.size() < 2)
                return true;

            int col = matrix.size();
            int row = matrix[0].size();
            for(int i = 0; i < row; ++i)  // 遍历第一行,判断是否符合条件
            {
                int srow = i + 1;
                int scol = 1;
                while(srow < row && scol < col)
                {
                    if(matrix[0][i] != matrix[scol][srow])
                        return false;
                    ++srow;
                    ++scol;
                }
            }

            for(int i = 1; i < col; ++i)    // 遍历第一列,判断是否符合条件
            {
                int scol = i + 1;
                int srow = 1;
                while(srow < row && scol < col)
                {
                    if(matrix[i][0] != matrix[scol][srow])
                        return false;
                    ++srow;
                    ++scol;
                }
            }
            return true;
        }
};
