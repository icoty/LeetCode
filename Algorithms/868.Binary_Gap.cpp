#include "AllInclude.h"

#define MAX(A,B) ((A)>(B)?(A):(B))

class Solution {
    public:
        int binaryGap(int N) {
            int cnt = 31;
            int one = -1;
            int ret = 0;
            while(cnt >= 0)
            {
                if((N >> cnt) & 1)
                {
                    if(-1 != one)
                    {
                        ret = MAX(ret, one - cnt);
                    }
                    one = cnt;
                }
                --cnt;
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
        int N = stringToInteger(line);

        int ret = Solution().binaryGap(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
