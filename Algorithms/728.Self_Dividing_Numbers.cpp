#include "AllInclude.h"

class Solution {
    public:
        bool isSastified(int num)
        {
            if(num < 10 && num >=1)
                return true;
            int tmp = num;
            while(tmp)
            {
                int mod = tmp % 10;
                if(0 == mod || 0 != num % mod)
                    return false;
                else
                {
                    tmp = tmp / 10;
                }
            }
            return true;
        }

        vector<int> selfDividingNumbers(int left, int right) {
            vector<int> ret;
            while(left < right)
            {
                if(isSastified(left))
                    ret.push_back(left);
                ++left;
            }

            if(left == right && isSastified(left))
                ret.push_back(left);
            return ret;   
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int left = stringToInteger(line);
        getline(cin, line);
        int right = stringToInteger(line);

        vector<int> ret = Solution().selfDividingNumbers(left, right);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
