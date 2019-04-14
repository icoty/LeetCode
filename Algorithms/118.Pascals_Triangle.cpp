#include "AllInclude.h"

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ret;
            if(0 == numRows)
                return ret;
            else
            {
                ret.resize(numRows);
                ret[0].push_back(1);

                if(1 == numRows)
                {
                    return ret;
                }
                else if(2 == numRows)
                {
                    ret[1].push_back(1);
                    ret[1].push_back(1);
                }
                else
                {
                    ret[1].push_back(1);
                    ret[1].push_back(1);
                    for(int i = 2; i < numRows; ++i)
                    {
                        int j = 0;
                        ret[i].push_back(1);
                        while(j < ret[i-1].size() - 1)
                        {
                            ret[i].push_back(ret[i-1][j] + ret[i-1][j+1]);
                            ++j;
                        }
                        ret[i].push_back(1);                    
                    }
                }
            }
            return ret;
        }
};
