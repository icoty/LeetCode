#include "AllInclude.h"

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() <= 0)
                return "";
            if(1 == strs.size())
                return strs[0];

            int min = 1 << 31 - 1;
            for(int i = 0; i < strs.size(); ++i)
                if(strs[i].size() < min)
                    min = strs[i].size();

            for(int i = 0; i < min; ++i)
            {
                bool flg = false;
                for(int j = 0; j < strs.size() - 1; ++j)
                {
                    if(strs[j][i] != strs[j + 1][i])
                    {
                        if(0 == i)
                            return "";
                        else
                            return strs[j].substr(0, i);
                    }
                }       
            }

            return strs[0].substr(0, min);

        }
};
