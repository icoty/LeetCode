#include "AllInclude.h"

bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            int l = 1;
            int r = n;
            while(l <=r)
            {
                int mid = l + (r - l ) / 2;  // 防止加法溢出,不建议用(l+r)/2
                if(isBadVersion(mid))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            return l;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int bad = stringToInteger(line);

        int ret = Solution().firstBadVersion(n, bad);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
