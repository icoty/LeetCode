#include "AllInclude.h"

/**
 *  * Definition for singly-linked list with a random pointer.
 *   * struct RandomListNode {
 *    *     int label;
 *     *     RandomListNode *next, *random;
 *      *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 *       * };
 *        */
class Solution {
    public: // https://www.cnblogs.com/grandyang/p/4261431.html
        RandomListNode *copyRandomList(RandomListNode *head) {
            if(!head)
                return NULL;
            RandomListNode* cur = head;
            while(cur){
                RandomListNode* tmp = new RandomListNode(cur->label);
                tmp->next = cur->next;
                cur->next = tmp;
                cur = tmp->next;
            }

            cur = head;
            while(cur){
                if(cur->random){
                    cur->next->random = cur->random->next;
                }
                cur = cur->next->next;
            }

            cur = head;
            RandomListNode* ret = head->next;
            while(cur){
                RandomListNode* tmp = cur->next;
                cur->next = tmp->next;
                if(tmp->next) 
                    tmp->next = tmp->next->next;
                cur = cur->next;
            }
            return ret;
        }
};
