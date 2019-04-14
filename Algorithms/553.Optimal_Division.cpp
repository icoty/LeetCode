#include "AllInclude.h"

class Solution {
    public: // https://blog.csdn.net/wyh476901857/article/details/70194941
        string optimalDivision(vector<int>& nums) {
            if(nums.size() == 1)
                return to_string(nums[0]);
            if(nums.size() == 2)
                return to_string(nums[0]) + "/" + to_string(nums[1]);

            string div = to_string(nums[1]);
            for(int i = 2; i < nums.size(); ++i){
                div += "/";
                div += to_string(nums[i]);
            }

            return to_string(nums[0]) + "/" + "(" + div + ")";
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        string ret = Solution().optimalDivision(nums);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
