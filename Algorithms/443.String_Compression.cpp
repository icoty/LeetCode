#include "AllInclude.h"

class Solution {
    public:
        int compress(vector<char>& chars) {
            int cnt = 0;
            int index = 0;
            for(int i = 0; i < chars.size(); ++i)
            {
                ++cnt;
                if(i == chars.size() - 1 || chars[i] != chars[1 + i])
                {   //  i == chars.size() - 1时不会判断后面一句,故下标不会溢出
                    chars[index++] = chars[i];
                    if(cnt != 1)
                    {
                        for(auto ele : to_string(cnt))
                            chars[index++] = ele;
                    }
                    cnt = 0;
                }
            }
            return index;
        }
};
