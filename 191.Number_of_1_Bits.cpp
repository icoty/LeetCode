#include "AllInclude.h"

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int bit = 0;
            while(n)
            {
                if(n % 2)
                    bit += 1;
                n >>= 1;
            }
            return bit;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().hammingWeight(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
