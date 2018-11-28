#include "AllInclude.h"

class Solution {
    public:
        bool isPowerOfTwo(int n) {
            return n > 0 && (n & n-1) == 0;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        bool ret = Solution().isPowerOfTwo(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
