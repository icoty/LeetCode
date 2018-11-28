#include "AllInclude.h"

class Solution {
    public:
        bool isVowels(char ch)
        {
            ch = tolower(ch);
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }

        string reverseVowels(string s) {
            if(s.size() < 2)
                return s;
            int l = 0; 
            int r = s.size() - 1;
            while(l < r)
            {
                while(l < r && !isVowels(s[l]))
                    ++l;
                while(l < r && !isVowels(s[r]))
                    --r;  
                if(l < r)
                {
                    swap(s[l], s[r]);
                    ++l;
                    --r;
                }
            }
            return s;
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
        string s = stringToString(line);

        string ret = Solution().reverseVowels(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
