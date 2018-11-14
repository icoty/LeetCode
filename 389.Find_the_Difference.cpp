#include "AllInclude.h"

class Solution {
    public:
        char findTheDifference(string s, string t) {

            char ret='\0';
            int i=0;
            for(;i<s.length();++i)
            {
                ret ^= s[i];
                ret ^= t[i];
            }

            ret ^= t[i];
            return ret;
        }
};

void trimLeftTrailingSpaces(string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                            return !isspace(ch);
                                            }));
}

void trimRightTrailingSpaces(string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                            return !isspace(ch);
                                            }).base(), input.end());
}

int main() {
    string source, target;
    while (getline(cin, source)) {
        getline(cin, target);
        trimLeftTrailingSpaces(source);       
        trimLeftTrailingSpaces(target);
        trimRightTrailingSpaces(source);
        trimRightTrailingSpaces(target);

        char ret = Solution().findTheDifference(source, target);

        cout << ret << endl;
    }   
    return 0;
}
