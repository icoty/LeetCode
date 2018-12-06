#include "AllInclude.h"

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> st(wordDict.begin(), wordDict.end());
            int m = s.size();
            vector<bool> dp(m + 1, false);
            dp[0] = true;
            for(int i = 1; i <= m; ++i){
                for(int j = i - 1; j >= 0; --j){
                    if(dp[j] && st.count(s.substr(j, i - j))){  // 从i包含i截取i-j长度的字符
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp.back();
        }
};
