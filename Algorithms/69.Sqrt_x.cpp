#include "AllInclude.h"
class Solution {
    public:
        int mySqrt(int x) {
            if(0 == x)
                return 0;
            if(x < 4)
                return 1;

            int l = 1;
            int r = x / 2;
            int ret = 0;
            while(l <= r)
            {
                int mid = ( l + r ) / 2;
                if(mid == double(x) / mid)  // 必须用double, float精度不够
                    return mid;
                else if(mid > double(x) / mid) 
                {
                    r = mid - 1;
                    if(r < double(x) / r)
                        return r;
                }
                else 
                {
                    l = mid + 1;
                    if(l > double(x) / l)
                        return mid;
                }
            }
            return 0;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
