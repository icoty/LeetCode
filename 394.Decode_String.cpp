#include "AllInclude.h"

class Solution {
    public:
        string decodeString(string s, int& i)
        {
            string ret = "";
            int num = 0;
            for(; i < (int)s.size(); ++i){
                char ch = s[i];
                if('[' == ch){
                    string cur = decodeString(s, ++i);
                    while(num-- > 0)    ret += cur;
                    ++num;
                }else if(ch >= '0' && ch <= '9'){
                    num = 10 * num + ch - '0';
                }else if(']' == ch){
                    return ret;
                }else{
                    ret += ch;
                }
            }
            return ret;
        }

        string decodeString(string s) {
            int i = 0;
            return decodeString(s, i);
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

        string ret = Solution().decodeString(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
