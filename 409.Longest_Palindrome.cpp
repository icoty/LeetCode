#include "AllInclude.h"

class Solution {
    public:
        int longestPalindrome(string s) {
            int len = 0;
            unordered_map<char, int> mp;
            for(int i = 0; i < s.size(); ++i)
            {
                ++mp[s[i]];
                if(0 == mp[s[i]] % 2)
                {
                    ++len;
                    mp[s[i]] -= 2;
                }
            }
            if(2 * len != s.size())
                return 2 * len + 1;
            else
                return 2 * len;
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

        int ret = Solution().longestPalindrome(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
