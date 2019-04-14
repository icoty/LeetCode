#include "AllInclude.h"

class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            int m = nums.size();
            nums.insert(nums.begin(), 1);
            nums.push_back(1);

            vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
            for(int l = 1; l <= m; ++l){
                for(int i = 1; i <= m - l + 1; ++i){
                    int end = i + l - 1;
                    for(int k = i; k <= end; ++k){
                        dp[i][end] = max(dp[i][end], dp[i][k - 1] + dp[k + 1][end] + nums[i - 1]*nums[end + 1]*nums[k]);
                    }
                }
            }
            return dp[1][m];
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

        int ret = Solution().maxCoins(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
