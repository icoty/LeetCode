#include "AllInclude.h"

class Solution {
    public:
        int calcBinaryOneCount(int num)
        {
            int ret = 0;  
            int i = 0;
            while(i < 20)   // 11110100001001000000=10^6 < 2^20
            {
                ret += 1 & (num >> i);
                ++i;
            }
            return ret;
        }

        bool isPrime(int num)
        {
            if(num <= 1)
                return false;

            int l = 2;
            int r = num / 2;
            while(l <= r)
            {
                if(0 == num % l)
                    return false;
                ++l;
            }
            return true;
        }

        int countPrimeSetBits(int L, int R) {
            int cnt = 0;
            while(L <= R)
            {
                cnt += (int)isPrime(calcBinaryOneCount(L));
                ++L;
            }
            return cnt;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int L = stringToInteger(line);
        getline(cin, line);
        int R = stringToInteger(line);

        int ret = Solution().countPrimeSetBits(L, R);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
