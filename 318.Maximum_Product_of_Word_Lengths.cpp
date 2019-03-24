#include "AllInclude.h"

class Solution {
public:
    int calc(string & l, string & r){
        vector<bool> v(26, false);
        for(auto & ele : l){
            v[ele - 'a'] = true;
        }
        
        for(auto & ele : r){
            if(v[ele - 'a'])
                return 0;
        }
        
        return r.size() * l.size();
    }
    int maxProduct(vector<string>& words) {
        int ret = 0;
        for(int i = 0; i < (int)words.size() - 1; ++i){
            for(int j = i + 1; j < words.size(); ++j){
                ret = max(ret, calc(words[i], words[j]));
            }
        }
        return ret;
    }
};
