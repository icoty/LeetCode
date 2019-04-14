#include "AllInclude.h"

class Solution {
    public:
        int findComplement(int num) {
            int ret = 0;
            int i = 31;
            while(!((num >> i) & 1))    // 寻找最左边的1所在位置
                --i;
            ++i;
            ret = num ^ (~0);           
            while(i < 32)
            {
                ret ^= 1 << i;
                ++i;
            }
            return ret;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        int ret = Solution().findComplement(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
