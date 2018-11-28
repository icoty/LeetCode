#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/5403783.html
        bool isPowerOfFour(int num) {
            return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
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
        int num = stringToInteger(line);

        bool ret = Solution().isPowerOfFour(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
