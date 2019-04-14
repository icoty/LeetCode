#include "AllInclude.h"

class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            int i = S.size() - 1;
            int j = T.size() - 1;
            int cnts = 0;
            int cntt = 0;
            while(i >= 0 || j >= 0)
            {
                while(i >= 0 && ('#' == S[i] || cnts > 0))
                {   
                    S[i--] == '#' ? ++cnts : --cnts;
#if 0
                    if('#' == s[i]){
                        ++cnts;
                        --i;
                    }else{
                        --cnts;
                        --i;
                    }
#endif
                }

                while(j >= 0 && ('#' == T[j] || cntt > 0))
                { 
                    T[j--] == '#' ? ++cntt : --cntt;
                }               

                if (i < 0 || j < 0) 
                    return i == j;

                if(S[i] != T[j])
                    return false;
                else
                {
                    --i;
                    --j;
                }
            }
            return i == j;
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
        string S = stringToString(line);
        getline(cin, line);
        string T = stringToString(line);

        bool ret = Solution().backspaceCompare(S, T);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
