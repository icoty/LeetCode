#include "AllInclude.h"

#define SWAP(A, B) {(A) ^= (B); (B) ^= (A); (A) ^= (B);}

class Solution {
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
            vector<vector<int>> ret;
            for(int k = 0; k < A.size(); ++k)
            {
                int i = 0, j = A[k].size() - 1;
                for(; i < A[k].size() / 2; ++i, --j)
                {
                    int tmp = (A[k][i] + 1) % 2;
                    A[k][i] = (A[k][j] + 1) % 2;
                    A[k][j] = tmp;
                }
                if(i == j)
                    A[k][i] = (A[k][i] + 1) % 2; // 长度为奇数时
            }
            return A;
        }
};
