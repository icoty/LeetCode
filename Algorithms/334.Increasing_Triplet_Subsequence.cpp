#include "AllInclude.h"


class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            int min1 = (1 << 31) - 1;
            int min2 = (1 << 31) - 1;
            for(auto ele : nums){
                if(ele <= min1)
                    min1 = ele;
                else if(ele <= min2)
                    min2 = ele;
                else
                    return true;
            }
            return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().increasingTriplet(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
