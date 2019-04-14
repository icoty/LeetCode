#include "AllInclude.h"

// https://blog.csdn.net/taoyanqi8932/article/details/52129450
class Solution {
    public:
        int trailingZeroes(int n) {
            int cnt = 0;
            while(n)
            {
                cnt += n / 5;
                n /= 5;
            }
            return cnt;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().trailingZeroes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
