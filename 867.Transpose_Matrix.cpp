#include "AllInclude.h"

class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& A) {
            vector<vector<int>> ret(A[0].size());
            for(int i = 0; i < A[0].size(); ++i)
            {
                for(int j = 0; j < A.size(); ++j)
                {
                    ret[i].push_back(A[j][i]);
                }
            }
            return ret;
        }
};
