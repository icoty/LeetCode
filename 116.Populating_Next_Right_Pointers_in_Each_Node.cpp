#include "AllInclude.h"

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
        void connect(TreeLinkNode *root) {
            TreeLinkNode* prev = root;
            TreeLinkNode* cur = NULL;
            while(prev){
                cur = prev;
                while(cur && cur->left){
                    cur->left->next = cur->right;   // 通过next遍历一层直至完毕之后再通过prev回到下一层
                    if(cur->next)
                        cur->right->next = cur->next->left;
                    cur = cur->next;
                }
                prev = prev->left;
            }
        }
};
