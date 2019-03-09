#include "AllInclude.h"

class Solution {
public: // https://www.cnblogs.com/hello-new-world/p/7337023.html
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        vector<vector<string>> ret(h, vector<string>(pow(2, h) - 1, ""));  
        dfs(root, ret, 0, 0, pow(2, h) - 1);
        return ret;
    }
    
    int height(TreeNode* root){
        if(!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    void dfs(TreeNode* root, vector<vector<string>>& ret, int row, int l, int r){
        if(!root)
            return;
        int mid = (l + r) / 2;
        ret[row][mid] = to_string(root->val);
        dfs(root->left, ret, row + 1, l, mid - 1);
        dfs(root->right, ret, row + 1, mid + 1, r);
    }
};
