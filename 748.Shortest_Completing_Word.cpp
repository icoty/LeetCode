#include "AllInclude.h"

class Solution {
    public:
        bool isLetter(char ch)
        {
            return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
        }

        string shortestCompletingWord(string licensePlate, vector<string>& words) {
            vector<int> ch(26, 0);
            for(int i = 0; i < licensePlate.size(); ++i)
                if(isLetter(licensePlate[i]))
                    ++ch[tolower(licensePlate[i]) - 'a'];

            int min = (1 << 31) - 1;
            int ret;
            for(int i = 0; i < words.size(); ++i)
            {
                vector<int> tmp(26, 0);
                for(auto ele: words[i])
                    ++tmp[ele - 'a'];

                int j = 0;
                while(j < 26)
                {
                    if(tmp[j] < ch[j])
                        break;
                    ++j;
                }

                if(26 == j && words[i].size() < min)
                {
                    min = words[i].size();  
                    ret = i;
                }
            }
            return words[ret];
        }
};
