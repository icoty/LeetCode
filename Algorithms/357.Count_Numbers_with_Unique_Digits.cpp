#include "AllInclude.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> v(11, 9); // {1, 10, v[i-1]+9*9, v[i-1]+9*9*8, v[i-1]+9*9*8*7, ……}
        v[0] = 1;
        v[1] = 10;
        for(int i = 2; i < 10; ++i){
            int tmp = i-1;
            for(int j = 9; j >= 1 && tmp--; --j){
                v[i] *= j;
            }
            v[i] += v[i - 1];
        }

        if(n >= 10)
            return v[9];
        else
            return v[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().countNumbersWithUniqueDigits(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
