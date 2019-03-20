#include "AllInclude.h"

class Solution {
public: // https://zhanghuimeng.github.io/post/leetcode-926-flip-string-to-monotone-increasing/
    int minFlipsMonoIncr(string S) {
        int l1 = 0;
        int r0 = 0;
        int r1 = 0;
        for(int i = 0; i < S.size(); ++i){
            if(S[i] == '0')
                ++r0;
            else
                ++r1;
            if(r0 > r1){
                l1 += r1;
                r0 = 0;
                r1 = 0;
            }
        }
        return l1 + r0;
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
        string S = stringToString(line);
        
        int ret = Solution().minFlipsMonoIncr(S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
