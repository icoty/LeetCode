#include "AllInclude.h"

class Solution {
public:
    Solution(vector<int> w)
    {
        int presum = 0;
        for(int i = 0; i < w.size(); ++i){
            presum += w[i];
            mp[presum - 1] = i;
        }
        sum = presum;
    }
    
    int pickIndex() {
        auto it = mp.upper_bound(rand() % sum);
        return it->second;
    }
private:
    map<int, int> mp;
    int sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
