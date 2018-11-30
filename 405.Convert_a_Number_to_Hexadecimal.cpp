#include "AllInclude.h"

class Solution {
    public:
        string toHex(int num) {
            string hx = "0123456789abcdef";
            int cnt = 0;
            string ret = "";
            while(num && cnt++ < 8)
            {
                ret = hx[num & 0xf] + ret;
                num >>= 4;
            }
            return ret.empty() ? "0" : ret;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().toHex(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
