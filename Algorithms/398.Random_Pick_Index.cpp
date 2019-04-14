#include "AllInclude.h"

class Solution {
public:
    Solution(vector<int> nums) 
    :num(nums)
    {
    }
    
    int pick(int target) {
        vector<int> tmp;
        for(int i = 0; i < num.size(); ++i)
            if(num[i] == target)
                tmp.push_back(i);
        return tmp[rand() % tmp.size()];
    }
private:
    vector<int> num;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
