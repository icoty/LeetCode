#include "AllInclude.h"

class Solution {
public: // https://www.cnblogs.com/zywscq/p/5415303.html
    int integerBreak(int n) {   // n拆分为整数和后求所有整数乘积最大值
        if(n <= 0)
            return 0;
        else if(n <= 2)
            return 1;
        else if(n == 3)
            return 2;
        else if(n % 3 == 1)
            return 2 * 2 * pow(3, (n - 4) / 3); // n * lgn
        else if(n % 3 == 2)
            return 2 * pow(3, (n - 2) / 3);
        else
            return pow(3, n / 3);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}å

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().integerBreak(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
