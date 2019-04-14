#include "AllInclude.h"

class Solution {
    public:
        bool isUpperLetter(char& ch)
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                ch += 32;
                return true;
            }
            return false;

        }
        string toLowerCase(string str) {
            for(int i = 0; i < str.size(); ++i)
                isUpperLetter(str[i]);
            return str;
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
        string str = stringToString(line);

        string ret = Solution().toLowerCase(str);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
