#include "AllInclude.h"

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode* merge2List(ListNode* l1, ListNode* l2)
        {
            if(!l1)
                return l2;
            if(!l2)
                return l1;

            if(l1->val > l2->val){
                ListNode* tmp = l1;
                l1 = l2;
                l2 = tmp;
            }

            ListNode* r = l1;
            ListNode* tail = r;

            l1 = l1->next;
            while(l1 && l2){
                if(l1->val < l2->val){
                    tail->next = l1;
                    l1 = l1->next;
                }else{
                    tail->next = l2;
                    l2 = l2->next;               
                }
                tail = tail->next;
            }

            if(!l1)
                l1 = l2;

            tail->next = l1;
            return r;
        }

        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(0 == lists.size())
                return NULL;
            int len = lists.size();
            while(len >= 2){
                int k = 0;
                int i = 0;

                for(i = 0; i < len - 1; i += 2)
                    lists[k++] = merge2List(lists[i], lists[i + 1]);

                if(i == len - 1)
                    lists[k++] = lists[i];
                len = k;
            }

            return lists[0];
        }
};
