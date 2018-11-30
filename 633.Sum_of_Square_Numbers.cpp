#include "AllInclude.h"

class Solution {
    public:
        bool judgeSquareSum(int c) {
            int a = sqrt(c);
            int b = sqrt(c - a * a);
            while(a >= b){
                if(a * a == c - b * b)
                    return true;
                --a;
                b = sqrt(c - a * a);
            }
            return false;
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
        int c = stringToInteger(line);

        bool ret = Solution().judgeSquareSum(c);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
