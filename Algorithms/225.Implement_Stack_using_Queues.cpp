#include "AllInclude.h"

class MyStack {
    public:
        /** Initialize your data structure here. */
        MyStack() {

        }

        /** Push element x onto stack. */
        void push(int x) {
            st.push(x);
            int i = 0;
            int len = st.size();
            while(i < len - 1)
            {
                st.push(st.front());
                st.pop();
                ++i;
            }
        }

        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            int tmp = st.front();
            st.pop();
            return tmp;
        }

        /** Get the top element. */
        int top() {
            return st.front();
        }

        /** Returns whether the stack is empty. */
        bool empty() {
            return 0 == st.size();
        }
    private:
        queue<int> st;
};

/**
 *  * Your MyStack object will be instantiated and called as such:
 *  * MyStack obj = new MyStack();
 *  * obj.push(x);
 *  * int param_2 = obj.pop();
 *  * int param_3 = obj.top();
 *    bool param_4 = obj.empty();
 *        */
