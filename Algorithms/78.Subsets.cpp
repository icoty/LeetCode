#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/4309345.html
        vector<vector<int>> subsets(vector<int>& nums) {
            sort(nums.begin(), nums.end()); //  排序后可按非降序输出
            vector<vector<int>> ret(1);
            for(int i = 0; i < nums.size(); ++i){
                int n = ret.size();
                for(int j = 0; j < n; ++j){
                    ret.push_back(ret[j]);
                    ret.back().push_back(nums[i]);
                }
            }
            return ret;
        }
};
