#include "AllInclude.h"

class Solution {
    public:
        int countPrimes(int n) {
            if(n <= 2)
                return 0;
            vector<bool> ret(n, true); // n个元素下标0~n-1
            ret[0] = ret[1] = false;   // 0 1非素数
            int qrt = sqrt(n);
            int cnt = 0; 
            for(int i = 2; i <= qrt; ++i)
            {
                if(!ret[i])
                {
                    continue;
                }
                for(int j = 2 * i; j < n; j += i) // j是i的倍数能被i整除,因此j不是素数
                {
                    ret[j] = false;
                }
            }
            for(int j = 0; j < ret.size(); ++j)
                cnt += ret[j] ? 1 : 0;
            return cnt;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().countPrimes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
