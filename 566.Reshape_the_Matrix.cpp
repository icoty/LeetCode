#include "AllInclude.h"

class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
            if(nums.size() * nums[0].size() != r * c)
                return nums;
            if(r == nums.size() && c == nums[0].size())
                return nums;

            vector<vector<int>> ret;        
            int cnt = 0;
            ret.resize(r);
            for(int i = 0; i < r; ++i)
            {
                for(int j = 0; j < c; ++j)
                {
                    ret[i].push_back(nums[cnt / nums[0].size()][cnt % nums[0].size()]);
                    ++cnt;
                }
            }
            return ret;
        }
};
