#include "AllInclude.h"

class Solution {
    public:
        vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
            unordered_map<string, int> str2index;
            map<int, vector<string>> ret;
            int minSum = (1 << 31) - 1;  
            for(int idx = 0; idx < list1.size(); ++idx)
                str2index[list1[idx]] = idx;

            for(int idx = 0; idx < list2.size(); ++idx)
                if(str2index.count(list2[idx]))
                {
                    if(str2index[list2[idx]] + idx < minSum)
                        minSum = str2index[list2[idx]] + idx;
                    ret[str2index[list2[idx]] + idx].push_back(list2[idx]);
                }

            return ret[minSum];
        }
};
