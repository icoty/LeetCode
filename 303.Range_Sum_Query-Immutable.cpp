#include "AllInclude.h"

class NumArray {
    public:
        NumArray(vector<int> nums) {
            dp.resize(nums.size() + 2, 0);
            for(int i = 1; i < nums.size() + 1; ++i)
                dp[i] = dp [i - 1] + nums[i - 1];
        }

        int sumRange(int i, int j) {
            return dp[j + 1] - dp[i];
        }
    private:
        vector<int> dp; // dp[i]为nums[0]~nums[i-1]求和
};
