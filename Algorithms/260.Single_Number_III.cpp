#include "AllInclude.h"

class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            vector<int> ret(2, 0);

            int sum = 0;
            for(auto & ele : nums){
                sum ^= ele; 
            }

            int bit = 1;
            while(!(sum & 0x01)){    // 找出最左边不同的位
                sum >>= 1;
                bit <<= 1;
            }

            for(auto & ele : nums){
                if(ele & bit)
                    ret[0] ^= ele;
                else
                    ret[1] ^= ele;
            }
            return ret;
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
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
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
        vector<int> nums = stringToIntegerVector(line);

        vector<int> ret = Solution().singleNumber(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
