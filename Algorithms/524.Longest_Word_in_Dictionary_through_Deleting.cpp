#include "AllInclude.h"

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ret = "";
        for(auto & ele : d){
            int i = 0, j = 0;
            for(; i < ele.size() && j < s.size();){
                if(ele[i] == s[j])
                    ++i;
                ++j;
            }
            if(i == ele.size() && ele.size() >= ret.size() )
                ret = ele.size() > ret.size() ? ele : ret < ele ? ret : ele;
        }
        return ret;
    }
};
