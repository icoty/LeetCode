#include "AllInclude.h"

class Solution {
    public:
        void recursive(vector<string>& ret, string str, int pos)
        {
            if(pos == str.size())
                ret.push_back(str);
            else if(str[pos] >= '0' && str[pos] <= '9')
                recursive(ret, str, pos + 1);
            else if(str[pos] >= 'a' && str[pos] <= 'z')
            {
                recursive(ret, str, pos + 1);
                str[pos] = toupper(str[pos]);
                recursive(ret, str, pos + 1);
            }
            else if(str[pos] >= 'A' && str[pos] <= 'Z')
            {
                recursive(ret, str, pos + 1);
                str[pos] = tolower(str[pos]);
                recursive(ret, str, pos + 1);
            }
        }

        vector<string> letterCasePermutation(string S) {
            if(0 == S.size())
                return {""};
            vector<string> ret;
            recursive(ret, S, 0);
            return ret;
        }
};
