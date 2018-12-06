#include "AllInclude.h"

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if(nums.size() <= 1)
                return true;
            int m = nums.size();
            vector<int> dp(m, false);
            dp[0] = nums[0] ? true : false;
            for(int i = 0; i < m; ++i)
            {
                for(int j = 1; j <= nums[i]; ++j)
                {
                    if(dp[i] && i + j < m)
                        dp[i + j] = true;
                }
            }

            return dp.back();
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

        bool ret = Solution().canJump(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
