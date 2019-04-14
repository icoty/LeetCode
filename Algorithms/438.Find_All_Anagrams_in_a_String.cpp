#include "AllInclude.h"

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            if(s.empty() || s.size() < p.size())
                return {};
            if(s.empty() || s.size() < p.size())
                return {};

            vector<int> sv(26, 0);
            vector<int> pv(26, 0);
            vector<int> ret;
            for(int i = 0; i < p.size(); ++i)
            {
                ++sv[s[i] - 'a'];
                ++pv[p[i] - 'a'];
            }
            if(sv == pv)
                ret.push_back(0);

            for(int i = p.size(); i < s.size(); ++i)
            {
                ++sv[s[i] - 'a'];
                --sv[s[i - p.size()] - 'a'];
                if(sv == pv)
                    ret.push_back(i - p.size() + 1);
            }
            return ret;

#if 0
            unordered_map<char, int> mp;
            vector<int> ret;
            int start = 0;
            for(int i = 0; start <= s.size() - p.size(); ++i)
            {
                ++mp[s[i]];
                if(i - start + 1 == p.size())
                {
                    int j = 0;
                    unordered_map<char, int> tmp(mp);
                    for(; j < p.size(); ++j)
                        if(--tmp[p[j]] < 0)
                            break;
                    if(j == p.size())
                        ret.push_back(start);

                    --mp[s[start]];
                    ++start;
                }
            }
#endif
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        vector<int> ret = Solution().findAnagrams(s, p);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
