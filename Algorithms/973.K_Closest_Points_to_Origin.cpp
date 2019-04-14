#include "AllInclude.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<double, set<vector<int> > > mp;
        
        for(auto & ele : points){
            mp[sqrt(ele[0] * ele[0] + ele[1] * ele[1])].insert(ele);
        }
        
        vector<vector<int>> ret;
        for(auto & ele : mp){
            for(auto & e : ele.second)
                if( K-- > 0)
                    ret.push_back(e);
        }
        
        return ret;
    }
};
