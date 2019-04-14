#include "AllInclude.h"

class Solution {
    public:
        bool hasAlternatingBits(int n) {
            int low_bit = -1;
            while(n)
            {
                int high_bit = n & 1;
                if(high_bit == low_bit) 
                    break;
                low_bit = high_bit;
                n >>= 1;
            }

            return n == 0;
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

        bool ret = Solution().hasAlternatingBits(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
