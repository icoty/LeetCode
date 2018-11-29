#include "AllInclude.h"

class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            pair<char, int> ch('\0', (1 << 31) - 1);
            pair<char, int> ch2('\0', (1 << 31) - 1);   // 没有比target大的字符时
            for(auto ele: letters)
            {
                cout << (ele - target);
                if(ele - target > 0 && ele - target < ch.second)
                {
                    ch = {ele, ele - target};
                }else if(ele - target < 0 && ele - target < ch2.second){
                    ch2 = {ele, ele - target};
                }
            }
            return ch.first != '\0' ? ch.first : ch2.first;
        }
};
