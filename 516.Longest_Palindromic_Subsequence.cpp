#include "AllInclude.h"
// https://www.cnblogs.com/grandyang/p/6493182.html?utm_source=itdadao&utm_medium=referral
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            if(0 == s.size())
                return 0;
            vector<vector<int>> dp(s.size(), vector<int>(s.size()));
            for(int i = s.size() - 1; i >= 0; --i){
                dp[i][i] = 1;
                for(int j = i + 1; j < s.size(); ++j){
                    if(s[i] == s[j]){   //  当i>j时, dp[i][j] = 0
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }else{
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
            return dp[0][s.size()-1];
        }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().longestPalindromeSubseq(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
