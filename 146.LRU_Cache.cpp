#include "AllInclude.h"

class LRUCache {
    public:
        LRUCache(int capacity)
            :cap(capacity)
        {

        }

        int get(int key) {
            if(!mp.count(key)){
                return -1;
            }

            li.splice(li.begin(), li, mp[key]); // 查找mp[key] 并移到链表头部
            return mp[key]->second;
        }

        void put(int key, int value) {
            if(!mp.count(key)){
                if(mp.size() == cap){
                    mp.erase(li.back().first);
                    li.pop_back();
                }
                li.push_front(make_pair(key, value));
                mp[key] = li.begin();
            }else{
                mp[key]->second = value;
                li.splice(li.begin(), li, mp[key]);
            }
        }

    private:
        int cap;
        list<pair<int, int>> li;
        unordered_map<int, list<pair<int, int>>::iterator > mp;
};

/**
 *  * Your LRUCache object will be instantiated and called as such:
 *   * LRUCache obj = new LRUCache(capacity);
 *    * int param_1 = obj.get(key);
 *     * obj.put(key,value);
 *      */
