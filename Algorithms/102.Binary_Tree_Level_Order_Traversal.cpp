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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(!root)
                return {};
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int m = q.size();

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
            return ret;
        }
    private:
        vector<vector<int>> ret;
};
