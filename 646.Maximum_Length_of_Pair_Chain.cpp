#include "AllInclude.h"

class Solution {
public: // https://www.cnblogs.com/grandyang/p/7381633.html
    int findLongestChain(vector<vector<int>>& pairs) {
        int ret = 0;
        int end = INT_MIN;
        sort(pairs.begin(), pairs.end(), [](vector<int> & a, vector<int> & b){ return a[1] < b[1];});
        for(auto & ele : pairs){
            if(ele[0] > end){
                ++ret;
                end = ele[1];
            }
        }
        return ret;
    }
};
