#include "AllInclude.h"

class RandomizedSet {
    public:
        /** Initialize your data structure here. */
        RandomizedSet() {

        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            if(0 != s.count(val))
                return false;
            s.insert(val);
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            if(0 == s.count(val))
                return false;
            s.erase(val);
            return true;
        }

        /** Get a random element from the set. */
        int getRandom() {
            int i = rand() % s.size();
            for(auto ele : s)
            {
                if(0 == i--)
                    return ele;
            }
        }

    private:
        unordered_set<int> s;
};

/**
 *  * Your RandomizedSet object will be instantiated and called as such:
 *   * RandomizedSet obj = new RandomizedSet();
 *    * bool param_1 = obj.insert(val);
 *     * bool param_2 = obj.remove(val);
 *      * int param_3 = obj.getRandom();
 *       */
