#include "AllInclude.h"

// //  https://leetcode.com/problems/decode-ways/discuss/186933/My-C%2B%2B-solution-beat-100-very-concise 动态规划解法
class Solution {
    public:
        int recurv(string& s, int idx)
        {
            if(s[idx] == '0')
                return 0;
            if(idx >= s.size() - 1)
                return 1;
            if(s[idx] > '2' || (idx + 1 < s.size() && s[idx] == '2' && s[idx + 1] >= '7'))
                return recurv(s, idx + 1);
            else if(s[idx] == '1' || (s[idx] == '2' && s[idx + 1] < '7'))
                return recurv(s, idx + 1) + recurv(s, idx + 2);
            else return 0;
        }
        int numDecodings(string s) {
            if(s.size() == 0)
                return 0;
            return recurv(s, 0);
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

        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
