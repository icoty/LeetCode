#include "AllInclude.h"

class Solution {
public:
    int minAreaRect(vector<vector<int>>& p) {
        set<pair<int, int>> st;
        for(auto ele : p){
            st.insert(make_pair(ele[0], ele[1]));
        }
        
        int ret = INT_MAX;
        for(int i = 0; i < p.size(); ++i){
            for(int j = 0; j < p.size(); ++j){
                int x1 = p[i][0], y1 = p[i][1];
                int x2 = p[j][0], y2 = p[j][1];
                if(i == j || x1 == x2 || y1 == y2 || abs(x1 - x2) * abs(y1 - y2) >= ret)
                    continue;
                if(st.count(make_pair(x1, y2)) && st.count(make_pair(x2, y1))){
                    ret = min(ret, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
