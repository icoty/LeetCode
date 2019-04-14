#include "AllInclude.h"


class Solution {
    public:
        void dfs(vector<int>& candidates, int start, vector<int>& path, int target)
        {
            if(target < 0)
                return;
            if(0 == target)
            {
                ret.push_back(path);
                return;
            }

            for(int i = start; i < candidates.size(); ++i)
            {
                path.push_back(candidates[i]);
                dfs(candidates, i, path, target - candidates[i]);
                path.pop_back();
            }
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> path;
            dfs(candidates, 0, path, target);
            return ret;
        }
    private:
        vector<vector<int>> ret;
};
