#include "AllInclude.h"

class Solution {
    public: //  http://www.cnblogs.com/grandyang/p/4800552.html
        int numSquares(int n) {
            while(0 == n % 4)   // 数学知识 & 动态规划
                n /= 4;
            if(7 == n % 8)
                return 4;
            for(int a = 0; a * a <= n; ++a) // 尝试是否能拆成两个数完全平方之和
            {
                int b = sqrt(n - a * a);
                if(a * a + b * b == n)
                    return !!a + !!b;
            }

            return 3;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().numSquares(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
