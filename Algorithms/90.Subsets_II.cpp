#include "AllInclude.h"

class Solution {
    public: // http://www.cnblogs.com/grandyang/p/4310964.html
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            if(nums.size() < 1)
                return {};
            sort(nums.begin(), nums.end()); //  排序后可按非降序输出
            vector<vector<int>> ret(1);
            int prev = nums[0];
            int prevS = ret.size();
            for(int i = 0; i < nums.size(); ++i){
                if(i > 0 && nums[i] != nums[i - 1]){
                    prev = nums[i];
                    prevS = ret.size();
                }

                int n = ret.size();
                for(int j = n - prevS; j < n; ++j){
                    ret.push_back(ret[j]);
                    ret.back().push_back(nums[i]);
                }
            }
            return ret;
        }
}; 
