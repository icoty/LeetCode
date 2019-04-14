#include "AllInclude.h"

class Solution {
    public:
        void dfs(vector<int>& v, int start, int k, vector<int>& path, int target)
        {
            if(path.size() > k || target < 0)
                return;
            else if(0 == target && k == path.size())
                ret.push_back(path);
            else{
                for(int i = start; i < v.size(); ++i)
                {
                    path.push_back(v[i]);
                    dfs(v, i + 1, k, path, target - v[i]);
                    path.pop_back();
                }
            }
        }

        vector<vector<int>> combinationSum3(int k, int n) {
            vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            vector<int> path;
            dfs(v, 0, k, path, n);
            return ret;
        }
    private:
        vector<vector<int>> ret;
};
