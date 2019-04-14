#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/Atanisi/p/7596135.html
        int findNumberOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size());
            vector<int> cnt(nums.size());
            int len = 0;
            int ret = 0;
            for(int i = 0; i < nums.size(); ++i){
                dp[i] = 1;
                cnt[i] = 1;
                for(int j = 0; j < i; ++j){
                    if(nums[i] > nums[j] && dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(nums[i] > nums[j] && dp[j] + 1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
                len = max(len, dp[i]);
            }
            for(int i = 0; i < dp.size(); ++i)
                if(len == dp[i])
                    ret += cnt[i];
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

        int ret = Solution().findNumberOfLIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
