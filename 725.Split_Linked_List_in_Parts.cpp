#include "AllInclude.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = 0;
        for(ListNode* cur = root; cur; ++size, cur = cur->next);
        
        int len = size / k;
        int mod = size % k;
        
        vector<ListNode*> ret(k);
        for(int i = 0; i < k && root; ++i){
            ret[i] = root;
            for(int j = 1; j < len + (i < mod); ++j)
                root = root->next;
            ListNode* tmp = root->next;
            root->next = NULL;
            root = tmp;
        }
        
        return ret;
    }
};
