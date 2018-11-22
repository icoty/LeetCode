#include "AllInclude.h"

class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> ret;
            for(int i = 0; i < n; ++i)
            {
                if(0 == (i+1) % 3 && 0 == (i+1) % 5)
                    ret.push_back("FizzBuzz");
                else if(0 == (i+1) % 3 && 0 != (i+1) % 5)
                    ret.push_back("Fizz");
                else if(0 != (i+1) % 3 && 0 == (i+1) % 5)
                    ret.push_back("Buzz");
                else
                    ret.push_back(to_string(i + 1));
            }
            return ret;
        }
};
