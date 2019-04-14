#include "AllInclude.h"

class Solution {
    public:
        bool canWinNim(int n) {
            return n % 4 >= 1 && n % 4 <= 3;
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

        bool ret = Solution().canWinNim(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
