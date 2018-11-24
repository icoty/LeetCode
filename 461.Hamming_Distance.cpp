#include "AllInclude.h"

class Solution {
    public:
        int hammingDistance(int x, int y) {
            int ret = 0;
            int i = 0;
            while(i < 31)
            {
                ret += ((x >> i) & 1) ^ ((y >> i) & 1);
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
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);

        int ret = Solution().hammingDistance(x, y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
