#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/7404777.html
#if 1
        int countSubstrings(string s) {
            int len = s.size();
            int ret = 0;
            for(int i = 0; i < len; ++i)
            {
                for(int j = 0; i-j >=0 && i+j < len && s[i-j] == s[i+j]; ++j)
                    ++ret;      // 回文子串长度为奇数
                for(int j = 0; i-1-j >=0 && i+j < len && s[i-1-j] == s[i+j]; ++j)
                    ++ret;      // 回文子串长度为偶数     
            }
            return ret;
        }
#else    
        int countSubstrings(string s) {
            int n = s.size(), res = 0;
            vector<vector<bool>> dp(n, vector<bool>(n, false));
            for (int i = n - 1; i >= 0; --i) {
                for (int j = i; j < n; ++j) {
                    dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                    if (dp[i][j]) ++res;
                }
            }
            return res;
        } 
#endif

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

        int ret = Solution().countSubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
