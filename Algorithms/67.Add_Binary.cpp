#include "AllInclude.h"

class Solution {
    public:
        string addBinary(string a, string b){
            string res = "";
            int m = a.size() - 1, n = b.size() - 1, carry = 0;
            while (m >= 0 || n >= 0) {
                int p = m >= 0 ? a[m--] - '0' : 0;
                int q = n >= 0 ? b[n--] - '0' : 0;
                int sum = p + q + carry;
                res = to_string(sum % 2) + res;
                carry = sum / 2; // 进位只会是1(如和为11,10),同理10进制相加进位只会是0~9
            }
            return carry == 1 ? "1" + res : res;
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
    // Examle Input: a = "11", b = "1"
    while (getline(cin, line)) {
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
