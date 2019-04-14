#include "AllInclude.h"

class Solution {
    public: // https://www.cnblogs.com/racaljk/p/9905941.html
        int minFallingPathSum(vector<vector<int>>& A) {
            vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));

            for(int i = 0; i < A[0].size(); ++i){
                dp[0][i] = A[0][i];
            }

            for(int i = 1; i < A.size(); ++i){
                for(int j = 0; j < A[0].size(); ++j){
                    if(j == 0){
                        dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                    }else if(j == A.size() - 1){
                        dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                    }else{
                        dp[i][j] = A[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
                    }
                }
            }

            return *min_element(dp[A.size() - 1].begin(), dp[A.size() - 1].end());
        }
};
