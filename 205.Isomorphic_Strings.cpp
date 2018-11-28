#include "AllInclude.h"

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if(s.size() != t.size())
                return false;
            map<char, char> s2t;
            map<char, char> t2s;
            for(int i = 0; i < s.size(); ++i)
            {
                if(s2t.count(s[i]) && t2s.count(t[i])){
                    if(s2t[s[i]] != t[i])
                        return false;
                }else if(s2t.count(s[i]) || t2s.count(t[i])){
                    return false;
                }else{
                    s2t[s[i]] = t[i];
                    t2s[t[i]] = s[i];
                }
            }
            return true;
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
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);

        bool ret = Solution().isIsomorphic(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
