#include "AllInclude.h"

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            if(0 == tasks.size())
                return 0;
            vector<int> ch(26, 0);
            for(auto ele : tasks)
                ++ch[ele - 'A'];
            sort(ch.begin(), ch.end());

            int i = 24;
            while(i >= 0 && ch[i] == ch[25]) --i;

            return max((int)tasks.size(), (ch[25] - 1) * (1 + n) + 25 - i);
        }
};
