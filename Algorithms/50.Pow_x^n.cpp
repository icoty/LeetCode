#include "AllInclude.h"

class Solution {
    public:
#if 0
        double myPow(double x, int n) {
            if(0 == n)
                return 1;
            if(n < 0)
            {
                int int_min = 1 << 31;
                int int_max = int_min - 1;
                if(int_min == n)
                    return 1.0 / (myPow(x, int_max)*x);
                else
                    return 1.0 / myPow(x, -n);
            }

            double ret = 1.0;
            for(; n; x *= x, n >>= 1)
            {
                if(n&1)
                    ret *= x;
            }

            return ret;   
        }   
#endif

        double myPow(double x, int n) {
            if(0 == n)
                return 1;
            if(n < 0)
            {
                int int_min = 1 << 31;
                int int_max = int_min - 1;
                if(int_min == n)
                    return 1.0 / (myPow(x, int_max)*x);
                else
                    return 1.0 / myPow(x, -n);
            }

            double half = myPow(x, n/2);
            if(n % 2)
                return half * half * x;
            else
                return half * half;   
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        double out = Solution().myPow(x, n);

        cout << out << endl;
    }
    return 0;
}
