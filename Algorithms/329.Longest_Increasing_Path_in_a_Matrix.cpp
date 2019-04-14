#include "AllInclude.h"

class Solution {
    public:
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = m > 0 ? matrix[0].size() : 0;   
            vector<vector<int>> path(m, vector<int>(n, 1));
            int ret = 0;
            bool flg = true;
            while(flg){
                flg = false;
                for(int i = 0; i < m; ++i){
                    for(int j = 0; j < n; ++j){
                        if(i > 0 && matrix[i - 1][j] < matrix[i][j] && path[i - 1][j] >= path[i][j]){
                            path[i][j] = path[i - 1][j] + 1;
                            flg = true;
                        }
                        if(i < m - 1 && matrix[i + 1][j] < matrix[i][j] && path[i + 1][j] >= path[i][j]){
                            path[i][j] = path[i + 1][j] + 1;
                            flg = true;
                        }
                        if(j > 0 && matrix[i][j - 1] < matrix[i][j] && path[i][j - 1] >= path[i][j]){
                            path[i][j] = path[i][j - 1] + 1;
                            flg = true;
                        }
                        if(j < n - 1 && matrix[i][j + 1] < matrix[i][j] && path[i][j + 1] >= path[i][j]){
                            path[i][j] = path[i][j + 1] + 1;
                            flg = true;
                        }                   
                        ret = max(ret, path[i][j]);
                    }
                }
            }
            return ret;
        }
};
