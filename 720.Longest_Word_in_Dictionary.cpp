#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/7817011.html
        string longestWord(vector<string>& words) {
            unordered_set<string> mp(words.begin(), words.end());
            queue<string> q;
            for(auto ele : words)
            {
                if(1 == ele.size())
                    q.push(ele);
            }

            int maxi = 0;
            string ret = "";
            while(!q.empty()){
                string tmp = q.front();
                q.pop();

                if(maxi < tmp.size()){
                    maxi = tmp.size();
                    ret = tmp;
                }else if(maxi == tmp.size()){
                    ret = min(ret, tmp);
                }

                for(char c = 'a'; c <= 'z'; ++c){
                    tmp.push_back(c);
                    if(mp.count(tmp))
                        q.push(tmp);
                    tmp.pop_back();
                }
            }
            return ret;
        }
};
