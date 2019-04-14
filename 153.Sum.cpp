#include "AllInclude.h"

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            if(nums.size() < 3 || nums.back() < 0 || nums.front() > 0)
                return {};
            int n = nums.size();
            for(int k = 0; k < n - 2; ++k)
            {
                if(nums[k] > 0)
                    break;
                if(k > 0 && nums[k] == nums[k - 1])
                    continue;
                int sum = 0 - nums[k];
                int i =  k + 1;
                int j = n - 1;
                while(i < j){
                    if(nums[i] == sum - nums[j]){
                        ret.push_back({nums[k], nums[i], nums[j]});
                        while(i < j && nums[i] == nums[i + 1])
                            ++i;
                        while(i < j && nums[j] == nums[j - 1])
                            --j;
                        ++i;
                        --j;
                    }else if(nums[i] < sum - nums[j]){
                        ++i;
                    }else{
                        --j;
                    }
                }
            }
            return ret;
        }
    private:
        vector<vector<int>> ret;
};
