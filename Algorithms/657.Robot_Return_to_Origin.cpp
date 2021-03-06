#include "AllInclude.h"

class Solution {
    public:
        bool judgeCircle(string moves) {
            int pan = 0;
            int tilt = 0;
            for(auto ele: moves)
            {
                switch(ele)
                {
                    case 'U':
                        {
                            ++tilt;
                            break;
                        }
                    case 'L':
                        {
                            ++pan;
                            break;
                        }
                    case 'D':
                        {
                            --tilt;
                            break;
                        }
                    case 'R':
                        {
                            --pan;
                            break;
                        }
                    default:
                        break;
                }
            }
            return 0 == pan && 0 == tilt;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string moves = stringToString(line);

        bool ret = Solution().judgeCircle(moves);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
