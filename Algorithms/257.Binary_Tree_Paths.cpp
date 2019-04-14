#include "AllInclude.h"

class Solution {
    public:
        void onePath(vector<string>& ret, string prev, TreeNode* root)
        {
            if(!root->left && !root->right)
            {
                ret.push_back(prev + to_string(root->val));         
            }
            else if(root->left && root->right)
            {
                onePath(ret, prev + to_string(root->val) + "->", root->left);
                onePath(ret, prev + to_string(root->val) + "->", root->right);
            }
            else if(root->left && !root->right)
            {
                onePath(ret, prev + to_string(root->val) + "->", root->left);
            }
            else if(!root->left && root->right)
            {
                onePath(ret, prev + to_string(root->val) + "->", root->right);
            }
        }

        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ret;
            if(!root)
                return ret;
            onePath(ret, "", root);    
            return ret;
        }
};
