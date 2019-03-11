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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    :size(0)
    ,root(new ListNode(-1))
    {
        root->next = head;
        while(head){
            ++size;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i = rand() % size;
        ListNode* cur = root->next;
        while(i > 0 && cur){
            cur = cur->next;
            --i;
        }
        return cur->val;
    }
    
private:
    ListNode* root;
    int size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
