#include "AllInclude.h"

/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(!root)
                return {};
            queue<TreeNode*> q;
            q.push(root);
            int cnt = 1;    
            while(!q.empty()){
                int m = q.size();
                ++cnt;
                vector<int> lev;
                for(int i = 0; i < m; ++i){
                    TreeNode* tmp = q.front();
                    q.pop();
                    lev.push_back(tmp->val);

                    if(tmp->left)
                        q.push(tmp->left);
                    if(tmp->right)
                        q.push(tmp->right);
                }

                ret.push_back(lev);
            }
            for(int i = 1; i < ret.size(); i += 2)
            {
                for(int j = 0; j < ret[i].size() / 2; ++j)
                    swap(ret[i][j], ret[i][ret[i].size() - 1 - j]);
            }
            return ret;
        }
    private:
        vector<vector<int>> ret;        
};
