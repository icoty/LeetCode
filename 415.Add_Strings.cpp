#include "AllInclude.h"

class Solution {
    public:
        string addStrings(string num1, string num2) {
            if(0 == num1.size())
                return num2;
            if(0 == num2.size())
                return num1;

            string ret = "";
            int carry = 0;
            int i = num1.size() - 1;
            int j = num2.size() - 1;
            while(i >= 0 || j >= 0){
                char m = i < 0 ? '0' : num1[i--];
                char n = j < 0 ? '0' : num2[j--];
                ret = to_string((carry + m + n - 96) % 10) +ret;    // 0的ascii为48
                carry = (carry + m + n - 96) / 10;
            }
            if(carry)
                ret = to_string(carry) + ret;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);

        string ret = Solution().addStrings(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
