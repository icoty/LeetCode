#include "AllInclude.h"

#define MAX(A,B) ((A)>(B)?(A):(B))

class Solution {
    public:
        int findLUSlength(string a, string b) {
            return a == b ? -1 : max(a.size(), b.size()); // 任何字符串本身都是一个子序列，空字符串是任何字符串的子序列
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        int ret = Solution().findLUSlength(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
