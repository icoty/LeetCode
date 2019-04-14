#include "AllInclude.h"

class Solution {
    public:
#if 1
        bool isPalindrome(string s) {
            int num = 0;
            for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
            {
                while(!isalnum(s[i]))
                    ++i;
                while(!isalnum(s[j]))
                    --j;
                if(i < j)
                {
                    num += (int)(tolower(s[i]));
                    num -= (int)(tolower(s[j]));
                    if(0 != num)
                        return false;
                }
            }
            return (num == 0);
        }  
#else
        bool isPalindrome(string s) {
            if(s.size() < 2)
                return true;
            int left = 0;
            int right = s.size() - 1 ;
            while(left <= right) 
            {
                while(!isAlphaNum(s[left])) 
                    ++left;
                while(!isAlphaNum(s[right]))
                    --right;
                if(left < right && tolower(s[left]) != tolower(s[right]))
                    return false;
                ++left; 
                --right;
            }
            return true;
        }
#endif    
        bool isAlphaNum(char &ch) {
            if (ch >= 'a' && ch <= 'z') return true;
            if (ch >= 'A' && ch <= 'Z') return true;
            if (ch >= '0' && ch <= '9') return true;
            return false;
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

        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
