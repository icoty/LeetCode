#include "AllInclude.h"

class Solution {
    public: // https://blog.csdn.net/fuxuemingzhu/article/details/79265829
        vector<int> partitionLabels(string S) {
            map<char, int> d;
            for (int i = 0; i < S.size(); i++) d[S[i]] = i;
            int start = 0, end = 0;
            vector<int> res;
            for (int i = 0; i < S.size(); i++) {
                end = max(end, d[S[i]]);
                if (i == end) {
                    res.push_back(end - start + 1);
                    start = end + 1;
                }
            }
            return res;
        }
};

