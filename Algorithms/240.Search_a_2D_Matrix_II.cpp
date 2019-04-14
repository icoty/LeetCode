#include "AllInclude.h"

class Solution {
    public:
        bool topright(vector<vector<int>>& matrix, int r, int c, int& target)
        {
            if(r >= matrix.size() || c < 0)
                return false;
            else if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] < target)
                return topright(matrix, r + 1, c, target);
            else
                return topright(matrix, r, c - 1, target);
        }

        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if(matrix.size() < 1 || matrix[0].size() < 1)
                return false;
            return topright(matrix, 0, matrix[0].size() - 1, target);
        }
};
