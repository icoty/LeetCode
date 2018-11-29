#include "AllInclude.h"

bool mycmp(const string& l, const string& r)
{
    return l > r;
}

class Solution {
    public: //  letter-log的identifier之后一定全是字母,digit-log的identifier之后一定全是数字
        bool isDigit(string s)
        {
            istringstream in(s);
            string word;
            in >> word;
            for(; in >> word;)
            {
                if(word[0] >= '0' && word[0] <= '9')
                    return true;
            }
            return false;
        }

        vector<string> reorderLogFiles(vector<string>& logs) {
            vector<string> letter;
            vector<string> digit;
            vector<string> ret;
            for(auto ele : logs)
            {
                if(isDigit(ele))
                    digit.push_back(ele);
                else
                    letter.push_back(ele);
            }
            sort(letter.begin(), letter.end(), [](auto& s1, auto& s2) {
                    int n1 = s1.length();
                    int n2 = s2.length();

                    int i = 0;
                    while (s1[i] != ' ') {
                    ++i;
                    }
                    int j = 0;
                    while (s2[j] != ' ') {
                    ++j;
                    }

                    string id1 = s1.substr(0, i);
                    string id2 = s2.substr(0, j);

                    ++i;
                    ++j;
                    while (i < n1 && j < n2) {
                    if (s1[i] != s2[j]) {
                    return s1[i] < s2[j];
                    }
                    ++i;
                    ++j;
                    }

                    if (i != 0) {
                        return false;
                    }
                    if (j != 0) {
                        return true;
                    }

                    return id1 < id2;
            });

            for(auto ele : letter)
                ret.push_back(ele);
            for(auto ele : digit)
                ret.push_back(ele);  
            return ret;
        }
};
