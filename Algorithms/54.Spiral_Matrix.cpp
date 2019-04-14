#include "AllInclude.h"

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            if(matrix.empty() || matrix[0].empty()) 
                return {};
            int up = 0;
            int down = matrix.size() - 1;
            int left = 0;
            int right = matrix[0].size() - 1;
            while(true){
                for(int j = left; j <= right; ++j) 
                    ret.push_back(matrix[up][j]);
                if(++up > down) 
                    break;
                for(int i = up; i <= down; ++i) 
                    ret.push_back(matrix[i][right]);
                if(--right < left) 
                    break;
                for(int j = right; j >= left; --j) 
                    ret.push_back(matrix[down][j]);
                if(--down < up) 
                    break;
                for(int i = down; i >= up; --i) 
                    ret.push_back(matrix[i][left]);
                if(++left > right) 
                    break;
            }
            return ret;
        }        
    private:
        vector<int> ret;
};
