#include "AllInclude.h"

class Solution {
    public:
        int largestPalindrome(int n) {
            int up = pow(10, n) - 1;
            int low = pow(10, n - 1);

            for(int i = up; i >= low; --i)  //  外层循环是从大到小遍历2*n位长的所有回文串
            {
                string tmp = to_string(i);
                long pal = stol(tmp + string(tmp.rbegin(), tmp.rend())); // 如999999 998899 …… 100001
                for(long j = up; j * j > pal; --j)  // j必须为long
                {
                    if(0 == pal % j)
                        return pal % 1337;
                }
            }
            return 9;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().largestPalindrome(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
