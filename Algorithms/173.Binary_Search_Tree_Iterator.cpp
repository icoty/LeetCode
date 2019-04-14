#include "AllInclude.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) 
    :cur(root)
    {
    }
    
    /** @return the next smallest number */
    int next() {
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        TreeNode* small = st.top();
        st.pop();
        cur = small->right;
        return small->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !st.empty();
    }
private:
    TreeNode* cur;
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
