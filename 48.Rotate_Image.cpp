#include "AllInclude.h"

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            vector<vector<int>> tmp(matrix.size(), vector<int>(matrix[0].size(), 0));
            for(int i = 0; i < matrix.size(); ++i)
            {
                for(int j = 0; j < matrix[0].size(); ++j)
                {
                    tmp[j][(int)matrix[0].size() - 1 - i] = matrix[i][j];
                }
            }
            matrix.clear();
            matrix = tmp;
        }
};
