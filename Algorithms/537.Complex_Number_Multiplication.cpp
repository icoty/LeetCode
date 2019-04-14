#include "AllInclude.h"

class Solution {
    public:
        string complexNumberMultiply(string a, string b) {
            int a1 = 0;
            int a2 = 0;
            int b1 = 0;
            int b2 = 0;
            getDigit(a, a1, a2);
            getDigit(b, b1, b2);
            cout << a1 << " " << a2 << " " << b1 << " " << b2;
            char ret[100] = {0};
            snprintf(ret, sizeof(ret), "%d+%di", a1 * b1 - a2 * b2, a1 * b2 + a2 * b1);

            return string(ret);
        }

        void getDigit(string& str, int& d1, int& d2){
            int i = str[0] == '-' ? 1 : 0;
            for(; str[i] != '+'; ++i){
                d1 = d1 * 10 + str[i] - '0';
            }

            if(str[0] == '-')
                d1 = 0 - d1;

            int j = str[i + 1] != '-' ? i + 1 : i + 2;

            for(; str[j] != 'i'; ++j){
                d2 = d2 * 10 + str[j] - '0';
            }  

            if(str[i + 1] == '-')
                d2 = 0 - d2;
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

        string ret = Solution().complexNumberMultiply(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
