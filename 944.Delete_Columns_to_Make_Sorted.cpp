#include "AllInclude.h"

class Solution {
    public:
        int minDeletionSize(vector<string>& A) {
            int ret = 0;
            if(A.size() < 1)
                return ret;
            for(int i = 0; i < A[0].size(); ++i)
            {
                int j = 0;
                while(j < A.size() - 1)
                {
                    if(A[j][i] > A[j+1][i])
                    {
                        break;
                    }
                    ++j;
                }
                if(j != A.size() - 1)
                    ret += 1;
            }

            return ret;
        }
};
