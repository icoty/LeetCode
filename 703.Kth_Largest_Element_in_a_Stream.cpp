#include "AllInclude.h"

class KthLargest {
    public:
        KthLargest(int k, vector<int> nums) 
            :K(k)
        {
            for(auto ele : nums)
                add(ele);
        }

        int add(int val) {
            if(kpq.size() < K || kpq.top() < val)
                kpq.push(val);  // 调整堆
            if(kpq.size() > K)
                kpq.pop();
            return kpq.top();
        }
    private:
        int K;
        priority_queue<int, vector<int>, greater<int>> kpq; // 小根堆,堆顶元素最小
};

/**
 *  * Your KthLargest object will be instantiated and called as such:
 *   * KthLargest obj = new KthLargest(k, nums);
 *    * int param_1 = obj.add(val);
 *     */
