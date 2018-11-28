#include "AllInclude.h"

class Solution {
    public:
        vector<vector<int>> largeGroupPositions(string S) {
            vector<vector<int>> ret;
            if(S.size() < 3)
                return ret;
            int start = 0;
            int i = 1;
            for(; i < S.size(); ++i)
            {
                if(S[i] != S[start])
                {
                    if(i - start >= 3)
                        ret.push_back({start, i - 1});
                    start = i;
                }
            }

            if(i - start >= 3)
                ret.push_back({start, i - 1}); 
            return ret;
        }
};
