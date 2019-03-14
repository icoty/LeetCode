#include "AllInclude.h"

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        string ret = "";
        auto it = mp[key].upper_bound(timestamp);   // 查找第一个大于timestamp的迭代器位置

        return it == mp[key].begin() ? "" : (--it)->second;
    }
private:
    unordered_map<string, map<int, string>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
