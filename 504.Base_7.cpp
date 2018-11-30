#include "AllInclude.h"

class Solution {
    public:
        string convertToBase7(int num) {
            if(0 == num)
                return "0";
            int tmp = abs(num);
            string ret = "";
            while(tmp){
                ret = to_string(tmp % 7) + ret;
                tmp /= 7;
            }
            return num > 0 ? ret : "-" + ret;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().convertToBase7(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
