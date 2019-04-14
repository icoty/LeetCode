#include "AllInclude.h"

class Solution {
    public:
        int addDigits(int num) {
            if(num < 10)
                return num;
            while(num >= 10)
            {
                int sum = 0;
                while(num)
                {
                    sum += num % 10;
                    num = num / 10;
                }
                num = sum;
            }
            return num;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        int ret = Solution().addDigits(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
