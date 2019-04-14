#include "AllInclude.h"

class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int r = matrix.size();
            if(0 == r)
                return 0;
            int c = matrix[0].size();
            int ret = 0;
            vector<vector<int>> dp(r, vector<int>(c, 0));
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(i > 0 && j > 0 && '1' == matrix[i][j]){
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }else{
                        dp[i][j] = matrix[i][j] - '0';
                    }
                    ret = max(ret, dp[i][j]);
                }
            }

            return ret * ret;
        }
};
