#include "AllInclude.h"

#include <map>

class Solution {
public:
    int findParent(unordered_map<int, int> & mp, int val){
        while(val != mp[val])
            val = mp[val];
        
        return val;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(auto & ele : edges){
            mp[ele[0]] = ele[0];
            mp[ele[1]] = ele[1];
        }

        for(auto & ele : edges){
            int l = findParent(mp, ele[0]);
            int r = findParent(mp, ele[1]);
            if(l == r)
                return ele;
            mp[l] = r;
        }
        return {0, 0};
    }
};
