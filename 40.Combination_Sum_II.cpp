#include "AllInclude.h"

class Solution {
    public:
        void dfs(vector<int>& candidates, int start, vector<int>& path, int target)
        {
            if(target < 0){
                return;
            }else if(0 == target){
                ret.push_back(path);
            }else{
                for(int i = start; i < candidates.size(); ++i)
                {
                    if(i > start && candidates[i] == candidates[i - 1])
                        continue;
                    path.push_back(candidates[i]);
                    dfs(candidates, i + 1, path, target - candidates[i]);
                    path.pop_back();
                }
            }
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            if(candidates.size() < 1)
                return ret;
            vector<int> path;
            sort(candidates.begin(), candidates.end());
            dfs(candidates, 0, path, target);
            return ret;
        }
    private:
        vector<vector<int>> ret;
};
