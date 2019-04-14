#include "AllInclude.h"

class Solution {
    public:
        int reverse(int x) {
            long long ret=0;
            while(x)
            {   
                int tmp = ret*10 + x % 10;
                if(ret != tmp/10) // x % 10作为余数不影响商的值
                    return 0;
                ret = tmp;
                x /= 10;    
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
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
