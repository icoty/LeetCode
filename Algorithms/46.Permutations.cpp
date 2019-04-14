#include "AllInclude.h"

class Solution {
    public:
        void dfs(vector<int>& nums, int start, vector<int>& path)
        {
            if(nums.size() == start)
                ret.push_back(path);
            for(int i = start; i < nums.size(); ++i)
            {
                path.push_back(nums[i]);
                swap(nums[i], nums[start]);
                dfs(nums, start + 1, path);
                swap(nums[i], nums[start]);
                path.pop_back();
            }
        }

        vector<vector<int>> permute(vector<int>& nums) {
            if(nums.size() < 1)
                return {};
            vector<int> path;
            dfs(nums, 0, path);
            return ret;
        }
    private:
        vector<vector<int>> ret;
};
