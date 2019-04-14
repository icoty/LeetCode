#include "AllInclude.h"

class Solution {
    public: //  http://www.cnblogs.com/grandyang/p/8456022.html
        int reachNumber(int target) {
            target = abs(target);
            int res = 0;
            int sum = 0;
            while(sum < target || (sum - target) % 2 == 1) 
            {
                ++res;
                sum += res;
            }
            return res;        
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int target = stringToInteger(line);

        int ret = Solution().reachNumber(target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
