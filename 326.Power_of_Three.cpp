#include "AllInclude.h"

class Solution {
    public:
        bool isPowerOfThree(int n) {
            if(0 == n)
                return false;
            double mod = log10(n) / log10(3);
            return (int)mod == mod;
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

        bool ret = Solution().isPowerOfThree(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
