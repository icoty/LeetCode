#include "AllInclude.h"

class Solution {
    public:
        vector<string> findRelativeRanks(vector<int>& nums) {
            vector<pair<int, int>> ele2i(nums.size());
            for (int i = 0; i < nums.size(); ++i)
                ele2i[i] = make_pair(nums[i], i);

            sort(ele2i.begin(), ele2i.end(), [](const auto& p1, const auto& p2) { return p1.first > p2.first; });   // lambda表达式

            vector<string> ret(nums.size());
            for (int i = 0; i < ele2i.size(); ++i)
            {
                if(0 == i)
                {
                    ret[ele2i[i].second] = "Gold Medal";
                }
                else if (i == 1)
                {
                    ret[ele2i[i].second] = "Silver Medal";
                }
                else if (i == 2)
                {
                    ret[ele2i[i].second] = "Bronze Medal";
                }
                else
                {
                    ret[ele2i[i].second] = to_string(i + 1);
                }
            }
            return ret;
        }        
};
