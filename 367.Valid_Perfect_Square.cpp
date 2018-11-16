#include "AllInclude.h"

class Solution {
    public:
        bool isPerfectSquare(int num) {
            if(1 == num)
                return true;

            int l = 1;
            int r = num / 2;
            while(l <= r)
            {
                int mid = ( l + r ) / 2;
                if(mid == num / mid)
                    return true;
                if(num / mid < mid) 
                    r = mid - 1;
                else 
                    l = mid + 1;
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
        int num = stringToInteger(line);

        bool ret = Solution().isPerfectSquare(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
