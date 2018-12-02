#include "AllInclude.h"

struct MyNode {
    int val;
    MyNode *next;
    MyNode *prev;
    MyNode(int x) : val(x), next(NULL), prev(NULL) {}
    MyNode(int x, MyNode* _prev, MyNode* _next) : val(x), prev(_prev), next(_next) {}
};

class MyLinkedList {
    public:
        /** Initialize your data structure here. */
        MyLinkedList(): size(0) {
            head = new MyNode(0);
            head->next = head->prev = head;
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index) {
            if(index < 0 || index >= size)
                return -1;
            return getNode(index)->val;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            MyNode* tmp = new MyNode(val);
            head->next->prev = tmp;
            tmp->next = head->next;
            head->next = tmp;
            tmp->prev = head;
            ++size;
        }

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            MyNode* tmp = new MyNode(val);
            head->prev->next = tmp;
            tmp->prev = head->prev;
            tmp->next = head;
            head->prev = tmp;
            ++size;
        }

        MyNode* getNode(int index)  // 定位至第index个节点(从0开始数)
        {
            if(index < 0 || index >= size)
                return NULL;
            if(index <= size / 2){  // 从左向右
                int i = 0;
                MyNode* cur = head->next;
                while(i++ < index){
                    cur = cur->next;
                }
                return cur;
            }

            int j = 0;
            int r = size - index - 1;
            MyNode* cur = head->prev;
            while(j++ < r){
                cur = cur->prev;
            }
            return cur;
        }

        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            if(index < 0 || index > size) 
                return;
            if(size == index){
                addAtTail(val);
                return;
            }

            if(0 == index){
                addAtHead(val);
                return;
            }

            MyNode* pindex = getNode(index);
            MyNode* tmp = new MyNode(val, pindex->prev, pindex);
            pindex->prev->next = tmp;
            pindex->prev = tmp;
            ++size;
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
            if(index >= size || index < 0)
                return;

            MyNode* pindex = getNode(index);
            pindex->next->prev = pindex->prev;
            pindex->prev->next = pindex->next;
            delete pindex;
            --size;
        }

        void print()
        {
            MyNode* cur = head->next;
            while(cur != head){
                cout << cur->val << " ";
                cur = cur->next;
            }
        }
    private:
        MyNode* head;
        int size;
};

/**
 *  * Your MyLinkedList object will be instantiated and called as such:
 *   * MyLinkedList obj = new MyLinkedList();
 *    * int param_1 = obj.get(index);
 *     * obj.addAtHead(val);
 *      * obj.addAtTail(val);
 *       * obj.addAtIndex(index,val);
 *        * obj.deleteAtIndex(index);
 *         */
