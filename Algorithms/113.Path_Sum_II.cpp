#include "AllInclude.h"

class Solution {
    public:
        void dfs(TreeNode* root, vector<int>& path, int tmp, int sum)
        {
            if(!root)
                return;
            tmp += root->val;
            path.push_back(root->val);
            if(tmp == sum && !root->left && !root->right)
                ret.push_back(path);
            dfs(root->left, path, tmp, sum);
            dfs(root->right, path, tmp, sum);
            path.pop_back();
        }

        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<int> one;
            int tmp = 0;
            dfs(root, one, tmp, sum);
            return ret;
        }
    private:
        vector<vector<int>> ret;
};
