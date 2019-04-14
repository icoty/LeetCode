#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/5852352.html
        int longestSubstring(string s, int k) {
            int i = 0;
            int ret = 0;
            while(i + k <= s.size()){   
                int mask = 0;   // 从右往左0~25位分别表示a~z,1表示出现次数小于k,0表示大于等于k
                int end = i;
                int ch[26] = {0};
                for(int j = i; j < s.size(); ++j){
                    if(++ch[s[j] - 'a'] < k)
                        mask |= (1 << s[j] - 'a');
                    else
                        mask &= ~(1 << s[j] - 'a');

                    if(0 == mask){
                        ret = max(ret, j - i + 1);
                        end = j;
                    }
                }
                i = end + 1;
            }
            return ret;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().longestSubstring(s, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
