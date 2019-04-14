#include "AllInclude.h"

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t ret = 0;
            int cnt = 0;
            while(cnt < 32)
            {
                if((n >> cnt) & 1)
                    ret |= 1 << (31 - cnt);
                ++cnt;
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
        int n = stringToInteger(line);

        int ret = Solution().reverseBits(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
