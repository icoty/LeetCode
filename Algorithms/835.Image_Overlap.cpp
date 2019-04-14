#include "AllInclude.h"

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> oneA, oneB;
        int m = A.size();
        for(int i = 0; i < m * m; ++i){
            if(A[i / m][i % m])
                oneA.push_back((i / m) * 100 + i % m);
            if(B[i / m][i % m])
                oneB.push_back((i / m) * 100 + i % m);   
        }
        
        unordered_map<int, int> move;
        int ret = 0;
        for(auto & ele : oneA){
            for(auto & e : oneB){
                ++move[e - ele];
                ret = max(ret, move[e - ele]);
            }
        }
        
        return ret;
    }
};
