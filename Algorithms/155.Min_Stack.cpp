#include "AllInclude.h"

class MinStack {
    public:
        /** initialize your data structure here. */
        MinStack() {

        }

        void push(int x) {
            if(0 == vec.size())
                vec.push_back(make_pair(x, 0));
            else if(x < vec[vec[vec.size() - 1].second].first)
                vec.push_back(make_pair(x, vec.size()));
            else
                vec.push_back(make_pair(x, vec[vec.size() - 1].second));
        }

        void pop() {
            vec.pop_back();
        }

        int top() {
            return vec[vec.size() - 1].first;
        }

        int getMin() {
            return vec[vec[vec.size() - 1].second].first;
        }
    private:
        vector<pair<int, int>> vec; // pair<val, index> index为以val为栈顶的所有元素的最小值索引
};

/**
 *  * Your MinStack object will be instantiated and called as such:
 *   * MinStack obj = new MinStack();
 *    * obj.push(x);
 *     * obj.pop();
 *      * int param_3 = obj.top();
 *       * int param_4 = obj.getMin();
 *        */
