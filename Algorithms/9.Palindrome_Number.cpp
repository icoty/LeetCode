#include "AllInclude.h"

class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0 || (x !=0 && 0 == x % 10))
                return false;
            if(x < 10)
                return true;

            int rSum = 0;
            while(x > rSum)
            {
                rSum = rSum * 10 + x % 10;
                x /= 10;
            }

            return (x == rSum) || (x == rSum / 10);

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
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
