#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/4452220.html
        vector<string> letterCombinations(string digits) {
            if(digits.size() < 1)
                return {};
            vector<string> word = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            vector<string> ret = {""};
            for(auto ele : digits){
                vector<string> temp;
                string tmp = word[ele - '2'];
                for(auto ch : tmp){
                    for(auto str : ret)
                        temp.push_back(str.append(1, ch));
                }
                ret = temp;
            }
            return ret;
        }
};
