#include "AllInclude.h"

class Solution {
    public:
        bool isOneBitCharacter(vector<int>& bits) {
            int len = bits.size();
            int i = 0;
            while(i < len - 1)
            {
                i += bits[i] + 1;  // bits[i]为0时加1, 为1时11 10都满足,故加2  
            }
            return i == len - 1;
        }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> bits = stringToIntegerVector(line);

        bool ret = Solution().isOneBitCharacter(bits);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
