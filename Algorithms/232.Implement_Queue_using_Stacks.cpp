#include "AllInclude.h"

class MyQueue {
    public:
        /** Initialize your data structure here. */
        MyQueue()
        {

        }

        /** Push element x to the back of queue. */
        void push(int x) {
            qin.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            if(qout.empty() && qin.empty())
                return -1;
            if(qout.empty())
                in2out();
            int tmp = qout.top();
            qout.pop();
            return tmp;
        }

        /** Get the front element. */
        int peek() {
            if(qout.empty() && qin.empty())
                return -1;
            if(qout.empty())
                in2out();
            return qout.top();
        }

        /** Returns whether the queue is empty. */
        bool empty() {
            return qout.empty() && qin.empty();
        }

    private:
        void in2out()
        {
            while(!qin.empty())
            {
                qout.push(qin.top());
                qin.pop();
            }
        }

        stack<int> qin;
        stack<int> qout;
};

/**
 *  * Your MyQueue object will be instantiated and called as such:
 *   * MyQueue obj = new MyQueue();
 *    * obj.push(x);
 *     * int param_2 = obj.pop();
 *      * int param_3 = obj.peek();
 *       * bool param_4 = obj.empty();
 *        */
