#include "AllInclude.h"

class Solution {
    public: //  https://leetcode.com/problems/shuffle-an-array/discuss/185289/First-Accepted-Solution-with-Explanation-C%2B%2BPython3-beats-89.45
        Solution(vector<int> nums): origin(nums) {

        }

        /** Resets the array to its original configuration and return it. */
        vector<int> reset() {
            return origin;
        }

        /** Returns a random shuffling of the array. */
        vector<int> shuffle() {
            vector<bool> flg(origin.size(), false);
            vector<int> shuff(origin.size(), 0);
            for(int i = 0; i < shuff.size(); ++i)
            {
                int index = rand() % shuff.size();
                while(flg[index] == true)
                    index = rand() % shuff.size();
                shuff[i] = origin[index];
                flg[index] = true;
            }
            return shuff;
        }
    private:
        vector<int> origin;
};
