#include "AllInclude.h"

class Solution {
    public:
#if 1
        vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
            vector<vector<int>> ret;
            ret.push_back({r0, c0});

            int cnt = 1;
            while(ret.size() != R * C){
                for(int i = 1; i <= cnt; ++i){
                    if(r0 >= 0 && r0 < R && c0 + i >= 0 && c0 + i < C)
                        ret.push_back({r0, c0 + i});
                }

                c0 += cnt;
                for(int i = 1; i <= cnt; ++i){
                    if(c0 >= 0 && c0 < C && r0 + i >= 0 && r0 + i < R)
                        ret.push_back({r0 + i, c0});
                }

                r0 += cnt;
                for(int i = 1; i <= cnt + 1; ++i){
                    if(r0 >= 0 && r0 < R && c0 - i >= 0 && c0 - i < C)
                        ret.push_back({r0, c0 - i});
                }

                c0 -= cnt + 1;
                for(int i = 1; i <= cnt + 1; ++i){
                    if(r0 - i >= 0 && r0 - i < R && c0 >= 0 && c0 < C)      
                        ret.push_back({r0 - i, c0});
                }  

                r0 -= cnt + 1;
                cnt += 2;
            }

            return ret;
        }


#else   // debug
        vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
            vector<vector<int>> ret;
            ret.push_back({r0, c0});

            int cnt = 1;
            while(ret.size() != R * C){
                for(int i = 1; i <= cnt; ++i){
                    if(r0 < 0 || r0 >= R || c0 + i < 0 || c0 + i >= C)
                        continue;
                    ret.push_back({r0, c0 + i});
                }

                c0 += cnt;
                for(int i = 1; i <= cnt; ++i){
                    if(c0 < 0 || c0 < C || r0 + i < 0 || r0 + i >= R)
                        continue;
                    ret.push_back({r0 + i, c0});
                }

                r0 += cnt;
                for(int i = 1; i <= cnt + 1; ++i){
                    if(r0 < 0 || r0 >= R || c0 - i < 0 || c0 - i >= C)
                        continue;
                    ret.push_back({r0, c0 - i});
                }

                c0 -= cnt + 1;
                for(int i = 1; i <= cnt + 1; ++i){
                    if(r0 - i < 0 || r0 - i >= R || c0 < 0 || c0 >= C) 
                        continue;
                    ret.push_back({r0 - i, c0});
                }  

                r0 -= cnt + 1;
                cnt += 2;
            }

            return ret;
        }
#endif
};
