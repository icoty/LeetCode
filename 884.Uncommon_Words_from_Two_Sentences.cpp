#include "AllInclude.h"

class Solution {
    public:
        void str2mp(unordered_map<string, int>& mp, string str)
        {
            istringstream in(str);
            string word;
            while(in >> word)
            {
                ++mp[word];
            }        
        }

        vector<string> uncommonFromSentences(string A, string B) {
            vector<string> ret;
            unordered_map<string, int> mp;
            str2mp(mp, A);
            str2mp(mp, B);        

            for(auto ele: mp)
            {
                if(1 == ele.second)
                    ret.push_back(ele.first);
            }
            return ret;
        }
};
