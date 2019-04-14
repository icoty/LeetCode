#include "AllInclude.h"

class Solution {
    public:
        bool isLetter(char ch)
        {
            return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
        }

        string reverseOnlyLetters(string S) {
            if(S.size() < 2)
                return S;
            int l = 0;
            int r = S.size() - 1;
            while(l < r)
            {
                while(l < r && !isLetter(S[l]))
                    ++l;
                while(l < r && !isLetter(S[r]))
                    --r;   
                if(l < r)
                {
                    char tmp = '\0';
                    tmp = S[l];
                    S[l] = S[r];
                    S[r] = tmp;
                    ++l;
                    --r;
                }
            }
            return S;
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

        string ret = Solution().reverseOnlyLetters(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
