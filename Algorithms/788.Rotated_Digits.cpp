#include "AllInclude.h"

class Solution {
    public:
        bool isGood(string num)
        {
            bool flag = false;
            for (auto i : num)
            {
                if (i == '3' || i == '4' || i == '7') // 只要有就一定不是
                    return false;            
                if (i == '2' || i == '5' || i == '6' || i == '9') // 如果遍历完了都没执行词语句,则不是
                    flag = true;
            }
            return flag;
        }
        int rotatedDigits(int N) {
            int cnt = 0;
            for(int i = 2; i <= N; ++i)
            {
                if(isGood(to_string(i)))
                    ++cnt;
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
        int N = stringToInteger(line);

        int ret = Solution().rotatedDigits(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
