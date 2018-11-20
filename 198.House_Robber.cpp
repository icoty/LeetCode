#include "Include.h"    

class Solution {
    public:
        int rob(vector<int>& nums) {
            int len = nums.size();
            int dp[len] = {0};
            dp[0] = nums[0];
            dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
            for(int i = 2; i < len; ++i)
            {
                dp[i] = (dp[i-2] + nums[i]) > dp[i-1] ? (dp[i-2] + nums[i]) : dp[i-1];
            }
            return dp[len-1];
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

        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
