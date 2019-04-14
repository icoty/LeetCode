#include "AllInclude.h"

// https://www.cnblogs.com/grandyang/p/5727892.html
class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            int r = matrix.size();
            int c = matrix[0].size();

            int low = matrix[0][0];
            int high = matrix[r - 1][c - 1];
            while(low < high){
                int mid = low + (high - low) / 2;
                if(lessThanMidCnt(matrix, k, mid))
                    high = mid;
                else
                    low = mid + 1;
            }
            return low;
        }

    private:
        bool lessThanMidCnt(vector<vector<int>>& matrix, int kth, int midNum)
        {
            int i = 0;
            int n = matrix.size();
            int j = matrix[0].size() - 1;
            int cnt = 0;
            while(i < n){
                while(j >= 0 && matrix[i][j] > midNum)  
                    --j;

                cnt += j + 1;   // j + 1为每一行小于等于midNum的数据个数
                ++i;
            }

            return cnt >= kth;
        }
};
