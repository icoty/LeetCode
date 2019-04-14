#include "AllInclude.h"

const int INT_32_MAX = (1 << 31) -1;
const int INT_32_MIN = 1 << 31;

class Solution {
    public:
        int invert(int absmin, int absmax)
        {
            if(0 == absmin)
                return absmax;
            if(absmin < 0)
                return invert(++absmin, --absmax);
            if(absmin > 0)
                return invert(--absmin, ++absmax);
        }

        int getSum(int a, int b) 
        {
            //cout << (abs(INT_32_MAX) > abs(INT_M32_IN)); // 特别注意此处输出 1
            if(INT_32_MAX == a && INT_32_MIN == b || INT_32_MAX == b && INT_32_MIN == a) 
                return -1;
            if(abs(a) > abs(b))
                return invert(b, a);
            else
                return invert(a, b);
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);

        int ret = Solution().getSum(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
