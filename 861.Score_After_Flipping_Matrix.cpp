#include "AllInclude.h"

class Solution {
    public: // https://leetcode.com/problems/score-after-flipping-matrix/discuss/144125/c%2B%2B-easy-understand-Greedy-method-with-explanation
        int matrixScore(vector<vector<int>>& A) {
            int r = A.size();
            int c = A[0].size();

            for(int i = 0; i < r; ++i){
                if(A[i][0] == 0){
                    for(int j = 0; j < c; ++j)
                        A[i][j] ^= 1;
                }
            }

            for(int i = 1; i < c; ++i){
                int cnt = 0;
                for(int j = 0; j < r; ++j){
                    cnt += A[j][i];
                }

                if(cnt <= (r >> 1)){    // 列中1的个数小于等于r/2
                    for(int j = 0; j < r; ++j)
                        A[j][i] ^= 1;
                }
            }

            int ret = 0;
            int bin = 1;
            for(int i = c - 1; i >= 0; --i){
                for(int j = 0; j < r; ++j){
                    ret += A[j][i] * bin;
                }
                bin <<= 1;
            }

            return ret;
        }
};

