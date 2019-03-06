#include "AllInclude.h"

class Solution {
    public:
        bool escapeGhosts(vector<vector<int>>& g, vector<int>& t) {
            for(int i = 0; i < g.size(); ++i){
                if(abs(g[i][0] - t[0]) + abs(g[i][1] - t[1]) <= abs(t[0]) + abs(t[1]))
                    return false;
            }

            return true;
        }
};
