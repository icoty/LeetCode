#include "AllInclude.h"
class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> ret;
            if(!root)
                return ret;

            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                vector<int> onelevel;
                int len = q.size();
                for(int i = 0; i < len; ++i)
                {
                    TreeNode* tmp = q.front();
                    q.pop();
                    onelevel.push_back(tmp->val);
                    if(tmp->left)
                        q.push(tmp->left);
                    if(tmp->right)
                        q.push(tmp->right);
                }
                ret.push_back(onelevel);
            }

            for(int i = 0; i < ret.size() / 2; ++i)
            {
                vector<int> tmp;
                tmp = ret[i];
                ret[i] = ret[ret.size() -1 -i];
                ret[ret.size() -1 -i] = tmp;
            }

            return ret;
        }
}
