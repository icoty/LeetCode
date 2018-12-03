#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/4358848.html
        void dfs(vector<int>& nums, int start)
        {
            if(nums.size() == start)
                ret.insert(nums);
            for(int i = start; i < nums.size(); ++i)
            {
                if(i != start && nums[i] == nums[start])
                    continue;
                swap(nums[i], nums[start]);
                dfs(nums, start + 1);
                swap(nums[i], nums[start]);
            }
        }

        vector<vector<int>> permuteUnique(vector<int>& nums) {
            if(nums.size() < 1)
                return {};
            dfs(nums, 0);
            return vector<vector<int>>(ret.begin(), ret.end());
        }
    private:
        set<vector<int>> ret;
};
