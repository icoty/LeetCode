#include "AllInclude.h"

class Solution {
    public:
        int uniqueMorseRepresentations(vector<string>& words) {
            vector<string> mos = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

            set<string> ret;
            for(auto ele: words)
            {
                string one;
                for(auto ch: ele)
                {
                    one += mos[ch - 'a'];
                }
                ret.insert(one);
            }
            return ret.size();
        }
};
