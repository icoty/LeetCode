#include "AllInclude.h"

class Solution {
    public:
        int arrangeCoins(int n) {
            int i = 0;
            while(n > i)
            {
                ++i;
                n -= i;
            }
            return i;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().arrangeCoins(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
