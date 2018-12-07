#include "AllInclude.h"

class Solution {
    public: // https://www.cnblogs.com/grandyang/p/5294255.html
        vector<int> countBits(int num) {
            vector<int> ret;
            for(int i = 0; i <= num; ++i){
                ret.push_back(bitset<32> (i).count());
            }
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
        int num = stringToInteger(line);

        vector<int> ret = Solution().countBits(num);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
