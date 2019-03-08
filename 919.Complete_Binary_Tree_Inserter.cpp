#include "AllInclude.h"

class CBTInserter {
    public:
        CBTInserter(TreeNode* root) {
            v.clear();
            v.push_back(NULL);
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                v.push_back(q.front());
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        int insert(int val) {
            TreeNode* tmp = new TreeNode(val);
            int len = v.size();
            if(len % 2){
                v[len / 2]->right = tmp;
            }else{
                v[len / 2]->left = tmp;
            }
            v.push_back(tmp);
            return v[len / 2]->val;
        }

        TreeNode* get_root() {
            return v[1];
        }
    private:
        vector<TreeNode*> v;
};
