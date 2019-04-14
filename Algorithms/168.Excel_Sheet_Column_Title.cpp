#include "AllInclude.h"

class Solution {
    public:
        string convertToTitle(int n) {
            string ret;
            while(n)
            {
                int mod = n % 26;
                if(0 == mod)
                    mod = 26;
                ret = char(64 + mod) + ret;
                n = (n - mod) / 26;
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
        int n = stringToInteger(line);

        string ret = Solution().convertToTitle(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
