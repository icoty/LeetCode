#include "AllInclude.h"

int guess(int num);

class Solution {
    public:
        int guessNumber(int n) {
            int feed;
            int l = 1;
            int r = n;
            int mid = l + (r - l) / 2;
            while(0 != (feed = guess(mid)))
            {
                if(-1 == feed)
                    r = mid - 1;
                else
                    l = mid + 1;
                mid = l + (r -l) / 2;
            }
            return mid;
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
        int pick = stringToInteger(line);

        int ret = Solution().guessNumber(n, pick);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
