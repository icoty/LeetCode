#include "AllInclude.h"

class Solution {
    public:
#if 0
        bool isMatch(string s, string p) {
            if(p.empty())
                return s.empty();
            if(p[0] != '*'){
                if(p[0] == s[0] || (p[0] == '?' && !s.empty()))
                    return isMatch(s.substr(1), p.substr(1));
                else
                    return false;
            }else{
                if(isMatch(s, p.substr(1))) // * 代替空序列的情况
                    return true;
                if(!s.empty())
                    return isMatch(s.substr(1), p);
                else
                    return false;
            }
        }
#else
        bool isMatch(string s, string p) {
            char *scur  = &s[0];
            char *sstar = NULL;
            char *pcur  = &p[0];
            char *pstar = NULL;
            while(*scur){
                if(*scur == *pcur || *pcur == '?'){
                    ++scur;
                    ++pcur;
                }else if(*pcur == '*'){
                    pstar = pcur++;
                    sstar = scur;
                }else if(pstar){
                    pcur = pstar + 1;
                    scur = ++sstar;
                }else
                    return false;
            }

            while(*pcur == '*')
                ++pcur;
            return !*pcur;
        }   
#endif
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
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
