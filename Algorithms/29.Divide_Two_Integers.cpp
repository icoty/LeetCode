#include "AllInclude.h"

class Solution {
    public: // 非常详细的讲解 https://leetcode.com/problems/divide-two-integers/discuss/13420/32-times-bit-shift-operation-in-C-with-O(1)-solution
        int divide(int A, int B) {
            if (A == INT_MIN && B == -1) 
                return INT_MAX;
            int a = abs(A);
            int b = abs(B);
            int res = 0;
            for(int x = 31; x >= 0; --x)
                if ((signed)((unsigned)a >> x) - b >= 0){
                    res += 1 << x;
                    a -= b << x;
                }
            return (A > 0) == (B > 0) ? res : -res;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);

        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
