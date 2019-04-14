#include "AllInclude.h"

// http://www.cnblogs.com/grandyang/p/4447233.html
// 1. 非快乐数一次循环必定包含4, 一次循环小于10
// 2. set<int>记录出现的数
class Solution {
    public:
        bool isHappy(int n){
            if(n <= 0)
                return false;
            int cnt = 10;
            while(cnt--)
            {
                int sum = 0;
                while(n)
                {
                    sum += (n % 10) * (n % 10);
                    n /= 10;
                }
                n = sum;
                if(1 == n)
                    return true;
            }
            return false;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        bool ret = Solution().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
