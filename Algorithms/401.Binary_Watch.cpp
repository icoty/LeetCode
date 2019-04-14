#include "AllInclude.h"

class Solution {
    public:
        vector<string> readBinaryWatch(int num) {
            vector<string> ret;
            for(int i = 0; i < 12; ++i)
            {
                bitset<4> h(i);
                for(int j = 0; j < 60; ++j)
                {
                    bitset<6> m(j);
                    if(m.count() + h.count() == num)
                        ret.push_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
                }
            }
            return ret;
        }
};
