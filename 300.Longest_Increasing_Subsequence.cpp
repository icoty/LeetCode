#include "AllInclude.h"

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            if(nums.size() < 1)
                return 0;
            int r = nums.size();
            vector<int> dp(r);

            int ret = 0;
            for(int i = 0; i < r; ++i)
            {
                dp[i] = 1;
                for(int j = 0; j < i; ++j)
                {
                    if(nums[i] > nums[j] && dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1;
                }
                ret = max(ret, dp[i]);
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().lengthOfLIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
