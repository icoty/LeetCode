#include "AllInclude.h"

class Solution {
    public:
        string customSortString(string S, string T) {
            int start = 0;
            for(auto & ele : S){
                for(int i = 0; i < T.size(); ++i){
                    if(ele == T[i])
                        swap(T[start++], T[i]);
                }
            }

            return T;
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
        getline(cin, line);
        string T = stringToString(line);

        string ret = Solution().customSortString(S, T);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
