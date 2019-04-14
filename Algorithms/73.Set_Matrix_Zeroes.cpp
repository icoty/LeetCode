#include "AllInclude.h"

class Solution {
    public: //  http://lib.csdn.net/article/datastructure/18467
        void setZeroes(vector<vector<int>>& matrix) {
            int r = matrix.size();
            int c = matrix[0].size();
            int r0 = false;
            int c0 = false; 
            for(int i = 0; i < r; ++i)
                if(0 == matrix[i][0])
                    c0 = true;  // 遍历第一列记录是否存在0

            for(int i = 0; i < c; ++i)
                if(0 == matrix[0][i])
                    r0 = true;  // 遍历第一行记录是否存在0

            for(int i = 0; i < r; ++i)
            {
                for(int j = 0; j < c; ++j)
                {
                    if(0 == matrix[i][j]){
                        matrix[0][j] = 0;   
                        matrix[i][0] = 0;   // 将(i,j)所在的行和列的第一个元素改为0,表示该行或该列最后需要全部修改为0
                    }
                }
            }

            for(int i = 1; i < r; ++i)
            {
                for(int j = 1; j < c; ++j)
                {
                    if(0 == matrix[i][0] || 0 == matrix[0][j])
                        matrix[i][j] = 0;
                }
            }

            if(r0){
                for(int i = 0; i < c; ++i)
                    matrix[0][i] = 0;
            }

            if(c0){
                for(int i = 0; i < r; ++i)
                    matrix[i][0] = 0;
            }
        }
};
