#include "AllInclude.h"

#define MIN(A,B) ((A)<(B)?(A):(B))

class Solution {
    public:
        vector<int> shortestToChar(string S, char C) {
            vector<int> result;
            for (int i = 0; i < S.size(); ++i)
            {
                int fpos = S.find_first_of(C,i);    // 查找位于i左边的第一个C字符,b不存在则返回-1
                int rpos = S.find_last_of(C,i);     // 查找位于i右边的第一个C字符
                int dist = 0; 
                if (fpos >= 0 && rpos >= 0)
                {
                    dist = MIN(abs(i-rpos), abs(fpos-i));
                }
                else if(fpos >= 0) 
                {
                    dist = fpos - i;
                } 
                else 
                {
                    dist = i - rpos;
                }
                result.push_back(dist);
            }
            return result;
        }     
};
