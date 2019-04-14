#include "AllInclude.h"

class Solution {
    public:
        bool isMatch(string word, string pattern)
        {
            if(word.size() != pattern.size())
                return false;

            vector<char> vw(256, 0), vp(256, 0);    // char 0~255
            for(int i = 0; i < word.size(); ++i){
                if(vw[word[i]] != vp[pattern[i]])
                    return false;
                vw[word[i]] = i + 1;
                vp[pattern[i]] = i + 1; // 记录下标
            }

            return true;
        }

        vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
            vector<string> ret;
            for(auto & ele : words){
                if(isMatch(ele, pattern)){
                    ret.push_back(ele);
                }
            }

            return ret;
        }
};
