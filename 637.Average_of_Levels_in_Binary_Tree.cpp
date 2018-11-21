#include "AllInclude.h"

class Solution {
    public:
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> ret;
            if(!root)
                return ret;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                int len = q.size();
                double sum = 0.0;
                for(int i = 0; i < len; ++i)
                {
                    TreeNode* tmp = q.front();
                    q.pop();
                    sum += tmp->val;
                    if(tmp->left)
                        q.push(tmp->left);
                    if(tmp->right)
                        q.push(tmp->right);
                }
                ret.push_back(sum / len);
            }
            return ret;
        }
};
