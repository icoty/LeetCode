#include "AllInclude.h"

class Solution {
    public:
        void recur(int l, int r, string one)
        {
            if(l > r)
                return;
            else if(0 == l && 0 == r)
                ret.push_back(one);
            else{
                if(l > 0)
                    recur(l - 1, r, one + "(");
                if(r > 0)
                    recur(l, r - 1, one + ")");
            }
        }

        vector<string> generateParenthesis(int n) {
            if(n <= 0)
                return {""};

            recur(n, n, "");
            return ret;
        }
    private:
        vector<string> ret;
};
