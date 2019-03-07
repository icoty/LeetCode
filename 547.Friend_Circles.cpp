#include "AllInclude.h"


class Solution {
    public:
        void dfs(vector<vector<int>>& M, int r, int c){
            for(int i = 0; i < M.size(); ++i){
                if(M[i][c] == 1){
                    M[i][c] = 0;
                    dfs(M, i, c);
                }

                if(M[c][i] == 1){
                    M[c][i] = 0;
                    dfs(M, c, i);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& M) {
            int ret = 0;
            for(int i = 0; i < M.size(); ++i){
                for(int j = 0; j < M.size(); ++j){
                    if(M[i][j] == 1){
                        M[i][j] = 0;
                        ++ret;
                        dfs(M, i, j);
                    }
                }
            }
            return ret;
        }
};
