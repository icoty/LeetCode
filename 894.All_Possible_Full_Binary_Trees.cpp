#include "AllInclude.h"

class Solution {
    public:
        vector<TreeNode*> allPossibleFBT(int N) {
            vector<TreeNode*> res;
            if (N == 1) {
                res.push_back(new TreeNode(0));
                return res;
            }
            N--;
            for (int i = 1; i < N; i += 2) {    // 左右子树节点必为奇数个
                for (auto& left : allPossibleFBT(i)) {
                    for (auto& right : allPossibleFBT(N - i)) {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        res.push_back(root);
                    }
                }
            }
            return res;
        }
};

