#include "AllInclude.h"

class MapSum {
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string pre) {
        int ret = 0;
        for(auto & ele : mp){
            if(ele.first.size() < pre.size())
                continue;

            if(ele.first.substr(0, pre.size()) == pre)
                ret += ele.second;
        }
        
        return ret;
    }
private:
    unordered_map<string, int> mp;
};
