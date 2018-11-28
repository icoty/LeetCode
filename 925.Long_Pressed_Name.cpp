#include "AllInclude.h"

class Solution {
    public:
        bool isLongPressedName(string name, string typed) {
            if(name.size() > typed.size())
                return false;  
            int i = 0;
            int j = 0;       
            for(; i < name.size() && j < typed.size();)
            {
                if(name[i] != typed[j] && typed[j] != name[i - 1])
                    return false;
                else if(name[i] != typed[j] && typed[j] == name[i - 1])
                {
                    ++j;
                }else{
                    ++i;
                    ++j;
                }
            }

            while(j < typed.size())
            {
                if(name[name.size() - 1] != typed[j])
                    return false;
                ++j;
            }     

            return i == name.size() && j == typed.size();
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
        string name = stringToString(line);
        getline(cin, line);
        string typed = stringToString(line);

        bool ret = Solution().isLongPressedName(name, typed);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
