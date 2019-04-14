#include "AllInclude.h"

class Solution {
    public: 
        int minimumDeleteSum(string s1, string s2) {
            vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
            int sum = 0;
            for(int i = 0; i < s1.size(); ++i)
            {
                sum += (int)s1[i];
                for(int j = 0; j < s2.size(); ++j)
                {
                    if(s1[i] == s2[j]){
                        dp[i+1][j+1] = dp[i][j] + (int)s1[i];   // 删除字符的ascii之和最小,等价于保留下来的最长公共子序列的ascii之和最大
                    }else{
                        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                    }
                }
            }

            for(auto ele : s2)
                sum += (int)ele;
            return sum - 2 * dp[s1.size()][s2.size()];
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
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);

        int ret = Solution().minimumDeleteSum(s1, s2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
