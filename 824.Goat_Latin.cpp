#include "AllInclude.h"

#define SWAP(A, B) {(A) ^= (B); (B) ^= (A); (A) ^= (B);}

class Solution {
    public:
        string toGoatLatin(string S) {
            string ret;
            if(0 == S.size())
                return ret;
            istringstream in(S);
            int i = 1;
            for(string word; in >> word; ++i)
            {
                if(!isVowel(word[0]))
                {
                    word.append(1, word[0]);
                    word = word.substr(1, word.size() - 1);

                }

                ret += (word + "ma").append(i, 'a').append(1, ' ');
            }
            return ret.substr(0, ret.size() - 1);
        }
    private:
        bool isVowel(char ch)
        {
            return 'A' == ch || 'E' == ch || 'I' == ch || 'O' == ch || 'U' == ch || 'a' == ch || 'e' == ch || 'i' == ch || 'o' == ch || 'u' == ch;
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

        string ret = Solution().toGoatLatin(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
